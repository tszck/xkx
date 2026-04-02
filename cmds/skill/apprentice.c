// apprentice.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object ob, old_app;
	mapping family/*, skills*/;
	int /*i,*/fealty;
//	string *skname;
	object room;
	object feng;
	int flag;
	
	seteuid(getuid());
	if (me->is_busy()) return notify_fail("你現在正忙着呢。\n");
	if( !arg ) return notify_fail("指令格式：apprentice | bai [cancel]|<對象>\n");
	if( arg=="cancel" )
	{
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("你現在並無拜任何人爲師的意思。\n");
		write("你改變主意不想拜" + old_app->name() + "爲師了。\n");
		tell_object(old_app, me->name() + "改變主意不想拜你爲師了。\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}
	if( !(ob = present(arg, environment(me))) || !ob->is_character() )
		return notify_fail("你想拜誰爲師？\n");
	if( !living(ob) || ob->query_temp("noliving") )
		return notify_fail("你必須先把" + ob->name() + "弄醒。\n");
	if( ob==me ) 
		return notify_fail("拜自己爲師？好主意....不過沒有用。\n");
	if( me->is_apprentice_of(ob) )
	{
		message_vision("$N恭恭敬敬地向$n磕頭請安，叫道：「師父！」\n", me, ob);
		return 1;
	}
	if( !mapp( ob->query("family") ) )
		return notify_fail( ob->name() + "既不屬於任何門派，也沒有開山立派，不能拜師。\n");

	// If the target is willing to recruit us already, we do it.
	if( (object)ob->query_temp("pending/recruit") == me )
	{
		if (me->query("detach/"+ob->query("family/family_name"))>0)
		{
			ob->delete_temp("pending/recruit");
			message_vision("$N看了看$n，搖了搖頭道：「你當年既然離開了"+ob->query("family/family_name")+"，今天又何必回來？」\n", ob, me);
			return 1;
		}

		fealty=(int)(me->query("family/fealty"));
		me->set_temp("fealty_temp",fealty);
		if( (me->query("family"))&&(string)me->query("family/family_name") !=
			(string)ob->query("family/family_name") )
		{
			if (me->query("combat_exp")>10000)
			{
				message_vision("$N經驗太高了，不能改投$n門下！！\n\n",me,ob);
				return 0;
			}
			message_vision("$N決定背叛師門，改投入$n門下！！\n\n$N跪了下來向$n恭恭敬敬地磕了四個響頭，叫道：「師父！」\n\n", me, ob);
			me->add("detach/"+me->query("family/family_name"),1);
			me->set("family/fealty", 0);
			me->set_temp("fealty_temp",0);
			me->add("betrayer", 1);
		}
		else 
		message_vision("$N決定拜$n爲師。\n\n$N跪了下來向$n恭恭敬敬地磕了四個響頭，叫道：「師父！」\n\n", me, ob);
		if ((string)me->query("family/master_id")=="feng qingyang")
		{
			room = find_object("/d/huashan/xiaofang");
			if (!objectp(room)) room = load_object("/d/huashan/xiaofang");
			feng = present("feng qingyang",room);
			if (!objectp(feng)) 
			{
				feng = new("/kungfu/class/huashan/feng");
				flag = 1;
			}
			feng->delete("students/"+me->query("id"));
			feng->set("no_accept/"+me->query("id"),1);
			feng->save_data();
			if (flag == 1) destruct(feng);
		}
		ob->recruit_apprentice(me);
		ob->delete_temp("pending/recruit");

		tell_object(ob, "恭喜你新收了一名弟子！\n");
		family = me->query("family");
		printf("恭喜您成爲%s的第%s代弟子。\n", me->query("family/family_name"), chinese_number( me->query("family/generation")));
		fealty=(int)(me->query_temp("fealty_temp"));
		me->set("family/fealty",fealty);
		me->delete_temp("fealty_temp");
		//me->set_temp("faint",200);
		return 1;
	}
	else
	{
		fealty=(int)(me->query("family/fealty"));
		me->set_temp("fealty_temp",fealty);
		old_app = me->query_temp("pending/apprentice");
		if( ob==old_app )
			return notify_fail("你想拜" + ob->name() + "爲師，但是對方還沒有答應。\n");
		else
			if( objectp(old_app) )
			{
				write("你改變主意不想拜" + old_app->name() + "爲師了。\n");
				tell_object(old_app, me->name() + "改變主意不想拜你爲師了。\n");
			}

		message_vision("$N想要拜$n爲師。\n", me, ob);
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) )
		{
			tell_object(ob, YEL "如果你願意收" + me->name() + "爲弟子，用 recruit 指令。\n" NOR);
		}
		else ob->attempt_apprentice(me);
		//fealty=(int)(me->query_temp("fealty_temp"));
		//me->set("family/fealty",fealty);
		//me->delete_temp("fealty_temp");
		me->set_temp("faint",200);
		return 1;
	}
}


int help(object me)
{
	write(@HELP
指令格式 : apprentice|bai [cancel]|<對象>
 
    這個指令能讓你拜某人爲師，如果對方也答應要收你爲徒的話，就會立即
行拜師之禮，但要等到對方用ｒｅｃｒｕｉｔ或ｓｈｏｕ指令收你爲弟子才能
正式拜師。請注意你已經有了師父，又背叛師門投入別人門下，江湖名譽會受
到影響，叛師對你以後的學習和前途都會造成影響。

    如果對你的師父使用這個指令，會變成向師父請安。
    如果使用的參數ｃａｎｃｅｌ則可以取消你剛纔的拜師之念（要在對方答
應之前實行哦；）。

    許多ＮＰＣ只接受平民百姓和本派弟子，而不接受別派弟子，叛師是有懲
罰的，所以選擇門派時要小心。

請參考相關指令 expell、recruit
HELP
	);
	return 1;
}