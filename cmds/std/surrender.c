// surrender.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object ob;
	
	if( !me->is_fighting() )
		return notify_fail("投降？現在沒有人在打你啊....？\n");

	ob = me->query_temp("last_opponent");
	if( objectp(ob) && ob->is_killing(me) &&
		living(ob) && !ob->query_temp("noliving") )
	{
		message_vision("$N向$n求饒，但是$N大聲説道：" + RANK_D->query_rude(me) + "廢話少説，納命來！\n", ob, me);
		return 1;
	}

	me->remove_all_enemy();
	if( (int)me->query("score") >= 50 )
		me->add("score", -50 );
	else
		me->set("score", 0);
	message_vision( HIW "\n$N説道：「不打了，不打了，我投降....。」\n\n" NOR, me);
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : surrender
 
    這個指令可以讓你向敵人投降而終止戰鬥。
 
HELP
	);
	return 1;
}
 
