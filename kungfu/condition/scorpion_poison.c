// scorpion_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me, HIG "你感到呼吸困難，四肢漸漸腫了起來。\n" NOR );
	me->receive_wound("jing", 10,"蠍子毒發作");
	me->receive_damage("qi", 10,"蠍子毒發作");
	me->apply_condition("scorpion_poison", duration - 1);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
