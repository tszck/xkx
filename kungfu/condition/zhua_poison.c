// zhua_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( duration < 1 ) return 0;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "痛苦地呻吟着。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"忽然一絲熱流自體內升起, 緩緩的浸入你四肢百骸。原來你中的凝血神抓發作了！\n"NOR );
		message("vision", me->name() + HIR "的身子突然一陣顫抖, 牙關咬得咯咯作響。\n"+me->name()+"忽然打了一個哆嗦,臉上露出痛苦而詭異的笑容。\n" NOR, environment(me), me);
	}
	me->receive_wound("qi",25 + random(20));
	me->receive_wound("jing", 25);
	me->set_temp("last_damage_from", "凝血神抓毒勁發作");
  if (me->is_ghost()) return 0;
	me->apply_condition("zhua_poison", duration - random(3));
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
