// ill_dongshang.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "肢體僵直，看來被凍傷了。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"你覺得肢體末端一陣僵直，看來是被凍傷了！\n" NOR );
		message("vision", me->name() + "的肢體僵直青腫，看來被凍傷了。\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"飢寒交迫凍死在"+environment(me)->query("short")+"了。");
	me->receive_damage("qi", 1,"飢寒交迫凍死在"+environment(me)->query("short")+"了。");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ill_dongshang", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}
