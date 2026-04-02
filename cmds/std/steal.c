// steal.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	string what, who;
	object ob, victim, thisroom;

	mapping myfam/*, vtfam*/;
	int sp, dp;
        thisroom = environment(me);

//	if(1==1)
//	return notify_fail("現在不許行竊。\n");
	if( environment(me)->query("no_fight"))
		return notify_fail("這裏禁止行竊。\n");

	if( environment(me)->query("no_steal"))
		return notify_fail("這裏禁止行竊。\n");

	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");

	if( me->query_temp("stealing") )
		return notify_fail("你已經在找機會下手了！\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
		return notify_fail("指令格式：steal <物品> from <人物>\n");

 //       if(arg=="corpse"||arg=="skeleton")
 //               return notify_fail("偷什麼偷，直接從屍體裏拿就是了！\n");
	victim = present(who, environment(me));
	if( !victim || victim==me)
		return notify_fail("你想行竊的對象不在這裏。\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能偷巫師身上的東西。\n");
		
	if (userp(me) && victim->query("owner") && me->query("id") != victim->query("owner"))
			return notify_fail("不許對此人行竊。\n");					

	if( victim->query("no_steal"))
		return notify_fail("不許對此人行竊。\n");

	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail("這種情況你還用得着偷嗎？\n"); 
	if(me->query("id") != victim->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("你身為捕快，執行公務，豈能知法犯法！\n");
	notify_fail("此人來頭不小，還是少惹為妙。\n");
	if (!userp(victim) && !victim->accept_hit(me)) return 0;

	if( !ob = present(what, victim) )
	{
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起來沒有什麼值錢的東西好偷。\n");
		ob = inv[random(sizeof(inv))];
	}

	if( !living(victim) || victim->query_temp("noliving") )
		return notify_fail(victim->name() + "好象不是活物，你直接取(get)就是了。\n"); 

	sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
		- (int)me->query("thief") * 20;

	if ( (myfam = me->query("family")) && myfam["family_name"] == "丐幫" )
		sp = (int)me->query_skill("stealing")*10+(int)me->query("kar")*5
			- (int)me->query("thief") * 20;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() )
	{
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("你不動聲色地慢慢靠近"+victim->name()+"，等待機會下手 ...\n\n");

        thisroom->set_temp("no_sleep",1);
        me->start_busy(2);
	me->set_temp("stealing", 1);
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp,int dp)
{
	mapping myfam/*, vtfam*/;
	int steal_level;
	me->delete_temp("stealing");

	if( environment(victim) != environment(me) )
	{
		tell_object(me, "太可惜了，你下手的目標已經走了。\n");
		return;
	}

	if( !living(victim) || victim->query_temp("noliving") ||
		(random(sp+dp) > dp) )
	{
		if( !present(ob, victim) )
		{
			tell_object(me,"你摸了半天沒發現自己要偷的東西，看來對方已經把東西轉移了！\n");
			return;
		}
		if( ob->query("no_steal") )
		{
			tell_object(me,"你摸到一"+ob->query("unit")+ob->name()
			+ "，可是你突然作賊心虛，居然不敢下手，真是可惜了。\n");
			return;
		}
		if( ob->query_temp("is_rided_by") )
		{
			tell_object(me,"你摸到一"+ob->query("unit")+ob->name()
			+ "，可是你發現那是人家的坐騎，真是可惜了。\n");
			return;
		}
		if( !ob->move(me) )
		{
			tell_object(me,"你摸到一"+ob->query("unit")+ob->name()
			+ "，可是對你而言太重了，不得不放棄。\n");
			return;
		}

		tell_object(me, HIW "得手了！\n\n" NOR);
		tell_object(me, "你成功地偷到一"+ob->query("unit")+ob->name() + "！\n");
		steal_level = (int)me->query_skill("stealing",1);

		if( living(victim) && !victim->query_temp("noliving") )
		{
			if ((int)me->query("combat_exp") >
				(steal_level*steal_level*steal_level/10) )
			{
				me->improve_skill("stealing", random(me->query("int")));
			}
			else
			{
				tell_object(me," 就這點經驗也要去偷？ \n");
			}
			if ( (myfam = me->query("family")) &&
				myfam["family_name"] == "丐幫" )
			{
//add by Java. Nov 16.1997
				me->start_busy(2);
				me->add("thief", 1);
				me->receive_damage("jing", 10);
				me->receive_wound("jing", 4);
				me->add("combat_exp",1);
				if( random(5) == 1) me->add("potential",1);
				
			}
		}

		if( random(sp) < dp/2 )
			message("vision", "你看到" + me->name() + "鬼鬼祟祟地從"
			+ victim->name() + "身上偷走了一" + ob->query("unit")
			+ ob->name()+"！\n", environment(me),({ me, victim }));
	}
	else
	{
		if( random(sp) > dp/2 )
		{
			tell_object(me, victim->name() + "不經意地一轉頭，你急忙將手縮了回去！\n還好，沒有被發現。\n");
			return;
		}
		tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
		message_vision("$N一回頭，正好發現$n的手正抓着$P身上的" + ob->name() + "！\n\n" + "$N喝道：「幹什麼！」\n\n", victim, me);
		me->improve_skill("stealing", 1, 1);

		me->delete("env/combatd");
		victim->delete("env/combatd");

		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(3);
		me->add("thief", 1);
		me->receive_damage("jing", 10);
		me->receive_wound("jing", 4);
	}
environment(me)->delete_temp("no_sleep");
}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

    這個指令讓你有機會偷到他人身上的東西。成功了，當然你就能獲
得該樣物品。可是，馬有失蹄，人總有失風的時候，當你失敗時當然就
得付出代價，至於是什麼代價......靠你自己去發掘羅。
HELP
	);
	return 1;
}
