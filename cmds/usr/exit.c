// /cmds/usr/quit.c
inherit F_DBASE;
inherit F_CLEAN_UP;

#include <command.h>
#include <ansi.h>


int savequit(object me);
void create() 
{
	seteuid(getuid());
	set("name", "離線指令");
	set("id", "quit");
	set("channel_id", "離線精靈");
}

int main(object me, string arg)
{
	if( time() - me->query("last/lastquit") < 30 && !wizardp(me))
		return notify_fail("你離上次離開遊戲的時間間隔不足，暫時無法離開遊戲。\n");
		
	if( environment(me)->query("no_quit"))
		return notify_fail("空間已經封閉，沒有人能夠退出這個時空了\n");

/*
	if( LOGIN_D->get_madlock()) 
		return notify_fail("時空已經封閉，沒有人能夠退出這個時空了。\n");
*/
	if( me->is_busy()) return notify_fail("你現在正忙着做其他事，不能退出遊戲！\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("身上帶的東西太多了，離不開遊戲了。\n");
	return savequit(me);
}
int savequit(object me)
{
	int i, t, e, p , pexp , ppot;
	int a=1;
	string ct, ce, cp;
	object *inv, link_ob, ob;
	string err;

        if( time()-me->query_temp("LAST_PKER_TIME")<7200&&!wizardp(me))
              return notify_fail("你剛殺人不久，暫時無法離開遊戲。\n");

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");
	if(me->query_temp("guardto"))
		environment(me)->delete("guarded/"+me->query_temp("guardto"));

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
// 巫師隱身退出時不記 last_login
		if(!wizardp(me) || !me->query("env/invisibility") )
		{
		    a=0;
			link_ob->set("last_on", time());
			link_ob->set("last_from", query_ip_name(me));
			a=(link_ob->save());
		}
		destruct(link_ob);
	}
	t=time()-me->query_temp("nowtime");
	if (t<=0) t=1;
	e=me->query("combat_exp")-me->query_temp("nowexp");
	p=me->query("potential")-me->query_temp("nowpot");
	pexp = e*3600 / t;
	ppot = p*3600 / t;
	ct=chinese_number(t/3600)+"小時"+chinese_number(t%3600/60)+"分鐘"+chinese_number(t%60)+"秒";
	ce=chinese_number(e);
	cp=chinese_number(p);
	log_file( "USAGE", sprintf("%-20s logout with %7d second, %6d exp, %6d pot, %6d exp/h %6d pot/h.\n", me->query("name")+"("+me->query("id")+")", t, e, p, pexp, ppot));
	if (e > 10000 || p > 5000 || e < -10000 || p < -5000)
		log_file( "NOTICE", sprintf("%-20s logout with %7d second, %6d exp, %6d pot. %6d exp/h %6d pot/h.\n", me->query("name")+"("+me->query("id")+")", t, e, p, pexp, ppot));

	write("你共停留了"+ct+"，長了"+ce+"經驗，和"+cp+"點潛能。\n");
	write("歡迎下次再來！\n");

	message("system", me->name() + "離開遊戲。\n", environment(me), me);
	CHANNEL_D->do_channel(this_object(), "sys", me->name() + "(" + me->query("id") + ")離開遊戲了。\n共停留了"+ct+"，長了"+ce+"點經驗，和"+cp+"點潛能。共清除 "+reclaim_objects()+" 個變數。\n");
	me->dismiss_team();
	me->set("last/lastquit", time());

//************* Added these for update topten ***********
	if( userp(me) )
		if( !wizardp(me) )
		{
			if (stringp(err= catch(ob=new("/clone/topten/magic-rice"))))
				message("channel:sys",me->name()+"topten建立失敗，請在線巫師儘快清查。\n"+err,users());
			if (objectp(ob))
			{
				if (stringp(err = catch(ob->movein(me))))
				message("channel:sys",me->name()+"topten移動失敗，請在線巫師儘快清查。\n"+err,users());
				if (stringp(err = catch(ob->savetopten(me))))
				message("channel:sys",me->name()+"topten保存失敗，請在線巫師儘快清查。\n"+err,users());
				destruct( ob );
			}
		}
//************* End of added ******************

    if ( a==1 &&	me->save() )
    {
    	destruct(me);
    	return 1;
    }
    else
    return notify_fail(HIR"警告：檔案保存失敗，無法退出遊戲，請馬上聯繫巫師解決。\n"NOR);
}

int help(object me)
{
	write(@HELP
指令格式 : quit | exit

    當你想暫時離開這個遊戲時，可利用此一指令。
HELP
	);
	return 1;
}
