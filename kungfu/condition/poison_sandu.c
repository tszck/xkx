// poison_sandu.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me, HIG "你的體內毒質在反撲自身了！\n" NOR );
	me->receive_wound("jing", 10,"體內巨毒反撲而");
	me->receive_damage("jing", 10,"體內巨毒反撲而");
	me->receive_wound("qi", 10,"體內巨毒反撲而");
	me->receive_damage("qi", 10,"體內巨毒反撲而");
//	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("poison_sandu", duration);
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
