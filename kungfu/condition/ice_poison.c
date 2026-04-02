//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "渾身顫抖，痛苦地哼了一聲。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"忽然一陣奇寒從丹田升起，沁入四肢百骸，你中的寒冰綿掌發作了！\n" NOR );
		message("vision", me->name() + "的身子突然晃了兩晃，牙關格格地響了起來。\n", environment(me), me);
	}
	me->receive_wound("qi",15 + random(10),"寒毒發作");
	me->receive_wound("jing", 10,"寒毒發作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ice_poison", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
