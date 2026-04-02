// jiebai.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object obj, old_target;

	if(me->query("age") < 15)
		return notify_fail("小孩子一邊玩兒去。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想和誰結拜？\n");
	if( !obj->is_character() )
		return notify_fail("看清楚一點，那並不是生物。\n");
	if( !userp(obj) )
		return notify_fail("你只能和玩家拜把子。\n");
	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail("嗯...你還是先把"+obj->name()+"弄醒吧。\n");
	if (me->query("jiebai") &&
		strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
		return notify_fail("你已經和人家結拜過了。\n");
	if(obj==me) return notify_fail("你不能和自己結拜。\n");

	if( userp(obj) && (object)obj->query_temp("pending/jiebai")!=me ) {
		message_vision("\n$N對着$n說道：" + RANK_D->query_self(me) + me->name() + "，對" + RANK_D->query_respect(obj)+ "心儀已久，願彼此生死與共，肝膽相照！\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/jiebai")) )
			tell_object(old_target, RED + me->name() + "取消了和你結拜的念頭。\n" NOR);
		me->set_temp("pending/jiebai", obj);
		tell_object(obj, YEL "如果你願意和對方結爲異姓骨肉，請你也對" + me->name() + "("+(string)me->query("id")+")"+ "下一次 jiebai 指令。\n" NOR);
		write(RED "對方必須同意才能結拜。你等着吧。\n" NOR);
		return 1;
	}

	message_vision("\n$N對着$n高聲說道：不求同年同月同日生，但願同年同月同日死！\n\n", me, obj);
	me->delete_temp("pending/jiebai");
	if(!me->query("jiebai")) me->set("jiebai", obj->query("id")+">");
	else me->set("jiebai", me->query("jiebai")+obj->query("id")+">");
	if(!obj->query("jiebai")) obj->set("jiebai", me->query("id")+">");
	else obj->set("jiebai", obj->query("jiebai")+me->query("id")+">");
	return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : jiebai <某人>
 
    這個指令用來和別人的結拜，當然對方必須也同意。

HELP
	);
	return 1;
}
