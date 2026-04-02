// reply.c
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/dns.h>



int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;
	object *inv;
	int i;
	string *clist=({});

	if( !arg || arg=="" )
		return notify_fail("你要回答什麼？\n");
	if (me->query_temp("quest_gift/got") && stringp(me->query_temp("quest_gift/type")))
	{
		inv = all_inventory(environment(me));
		for (i=0;i<sizeof(inv);i++)
		{
			if (inv[i]->is_manager())
				return inv[i]->accept_reply(me,inv[i],arg);
		}
	}
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("剛纔沒有人和你說過話。\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("網路訊息已送出，可能要稍候才能得到回應。\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj) || obj->query_temp("block_msg/all"))
		return notify_fail("剛纔和你說話的人現在無法聽見你，或者已經離開遊戲了。\n");
	if (stringp(obj->query("env/can_tell")))
	clist = explode(obj->query("env/can_tell"),",");
	if (!wizardp(me) && (obj->query("env/no_tell")=="all" || obj->query("env/no_tell")==me->query("id")) 
	&& (!arrayp(clist) || member_array(me->query("id"),clist)==-1))
		return notify_fail("這個人不想聽你羅嗦啦。\n");
	write(HIG "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
	tell_object(obj, sprintf(HIG "%s回答你：%s\n"NOR,
		me->name(1)+"("+me->query("id")+")", arg));
	if (stringp(obj->query("env/auto_reply")) && query_idle(obj)>60)
	tell_object(me,HIW"(自動回覆)"NOR+obj->name()+"回答你："+obj->query("env/auto_reply")+"\n");
	message("channel:snp", HIB"【監聽】"+me->query("name")+"回答"+obj->query("name")+"："+arg+"\n"NOR, users());
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply <訊息>

    你可以用這個指令和剛纔用 tell 和你說話的使用者說話。

see also : tell
HELP
	);
	return 1;
}
