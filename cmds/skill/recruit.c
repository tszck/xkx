//recruit.c
// 增加升過袋的丐幫弟子不能投別派。
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int /*i,*/fealty;
//	string temp;
//	int student_num;
	object feng,room;
	int flag;

	if (!arg)
		return notify_fail("指令格式：recruit|shou [cancel]|<對象>\n");
	if (arg=="cancel")
	{
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("你現在並沒有收錄任何人爲弟子的意思。\n");
		write("你改變主意不想收" + old_rec->name() + "爲弟子了。\n");
		tell_object(old_rec, me->name()+"改變主意不想收你爲弟子了。\n");
		me->delete_temp("pending/recruit");
		return 1;
	}
          if(arg=="corpse"||arg=="skeleton")
           	return notify_fail("看清楚一點，那並不是生物。\n");
//        if(!living(ob)||ob->query_temp("noliving"))
//              return notify_fail("看清楚一點，那不是人。\n");

	if (!(ob=present(arg,environment(me))))
		return notify_fail("你想收誰作弟子？\n");
	if (ob==me)
		return notify_fail("收自己爲弟子？好主意....不過沒有用。\n");
	if (ob->is_apprentice_of(me))
	{
		message_vision("$N拍拍$n的頭，說道：「好徒兒！」\n", me, ob);
		return 1;
	}
	if (!me->query("family"))
		return notify_fail("你並不屬於任何門派，你必須先加入一個門派，或自己創一個才能收徒。\n");
	if( ob->query("party") &&
		ob->query("party/party_name") == HIC"丐幫"NOR &&
		me->query("family/family_name") != "丐幫")
	{
		message_vision("$N看了看$n，搖了搖頭道：「你是丐幫有袋弟子，還是回丐幫去吧。」\n", me, ob);
		return 1;
	}
	if (me->accept_betrayer(ob))
	{
		message_vision("$N看了看$n，忽然又搖了搖頭道：「你生性反覆，無緣承接本門衣鉢，好自爲之吧。」\n", me, ob);
		return 1;
	}
// If the target is willing to apprentice us already, we do it.
	if ((object)ob->query_temp("pending/apprentice") == me)
	{
  	if (ob->query("detach/"+me->query("family/family_name"))>0)
  	{
		message_vision("$N看了看$n，搖了搖頭道：「你當年既然離開了"+me->query("family/family_name")+"，今天又何必回來？」\n", me, ob);
		return 1;
		}
		if (!living(ob) || ob->query_temp("noliving") )
		{
			message_vision("$N決定收$n爲弟子。\n\n不過看樣子$n顯然沒有辦法行拜師之禮。\n\n",me, ob);
			return 1;
		}
// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		if((ob->query("family")) && (me->query("family")) &&
			( (string)me->query("family/family_name") !=
			(string)ob->query("family/family_name") ) )
		{
// Modified by That Oct.17 1997
			if (ob->query("title")=="隱士" ||ob->query("combat_exp")<100000) 
			{
   	    ob->add("detach/"+ob->query("family/family_name"),1);
				message_vision("$N決定屈尊投入$n門下！！\n\n$N跪了下來向$n恭恭敬敬地磕了四個響頭，叫道：「師父！」\n\n$N心裏卻大叫辣塊媽媽！\n\n", ob, me);
				ob->set_temp("fealty_temp",0);
				ob->set("score", 0);
				ob->add("betrayer", 1);
		    ob->delete("perform");		
			}
			else
			{
				message_vision("$N拍了拍$n的腦門：怪！經驗這麼高！嘿嘿，我可不敢收你了。\n", me, ob);
				return 1;
			}
		}
		else
		{
			message_vision("$N決定收$n爲弟子。\n\n$n跪了下來向$N恭恭敬敬地磕了四個響頭，叫道：「師父！」\n", me, ob);
 		}
		if ((string)ob->query("family/master_id")=="feng qingyang")
		{
			room = find_object("/d/huashan/xiaofang");
			if (!objectp(room)) room = load_object("/d/huashan/xiaofang");
			feng = present("feng qingyang",room);
			if (!objectp(feng)) 
			{
				feng = new("/kungfu/class/huashan/feng");
				flag = 1;
			}
			feng->delete("students/"+ob->query("id"));
			feng->set("no_accept/"+ob->query("id"),1);
			feng->save_data();
			if (flag == 1) destruct(feng);
		}
		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");
		fealty=(int)(ob->query_temp("fealty_temp"));
		ob->set("family/fealty",fealty);
		ob->delete_temp("fealty_temp");

		if ((ob->query("class")!="bonze") &&
			(me->query("class")!="bonze") &&
			(ob->query("class")!="lama") &&
			(me->query("class")!="lama") &&
			(ob->query("class")!="quanzhen") &&
			(me->query("class")!="quanzhen") &&
			(ob->query("class")!="eunach") &&
			(me->query("class")!="eunach"))
			ob->set("class",me->query("class"));
	
		write("恭喜你新收了一名弟子！\n");
		family = ob->query("family");
		tell_object( ob, sprintf("恭喜您成爲%s的第%s代弟子。\n", family["family_name"], chinese_number(family["generation"]) ));
		return 1;
	}
	else
	{
		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
		return notify_fail("你想收" + ob->name() + "爲弟子，但是對方還沒有答應。\n");
		else if( objectp(old_rec) )
			{
				write("你改變主意不想收"+old_rec->name()+"爲弟子了。\n");
				tell_object(old_rec,me->name()+"改變主意不想收你爲弟子了。\n");
			}
		me->set_temp("pending/recruit", ob );
		message_vision("\n$N想要收$n爲弟子。\n", me, ob);
		tell_object(ob, YEL "如果你願意拜" + me->name() + "爲師父，用 apprentice 指令。\n" NOR);
		return 1;
	}
}


int help(object me)
{
	write(@HELP
指令格式 : recruit|shou [cancel]|<對象>

    這個指令能讓你收某人爲弟子，如果對方也答應要拜你爲師的話。

See Also: apprentice
HELP
	);
	return 1;
}