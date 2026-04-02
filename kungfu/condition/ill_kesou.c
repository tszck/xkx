// ill_kesou.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "嘶啞着嗓子咳了兩聲，看來是病了。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"你嘶啞着嗓子咳了兩聲，然後又連續咳了好一陣，看來是病了不輕！\n" NOR );
		message("vision", me->name() + "的身子弓着身子晃了兩晃，嘶啞着嗓子咳了兩聲，看來是病了。\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"舊病復發，久病無醫而亡了。");
	me->receive_damage("qi", 1,"舊病復發，久病無醫而亡了。");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ill_kesou", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}
