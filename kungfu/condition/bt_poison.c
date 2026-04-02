// Last Modified by winder on May. 15 2001
// bt_poison.c 白駝怪蛇毒
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") ) return CND_CONTINUE;
	tell_object(me, HIB "你忽然感到身體僵直，已經不聽使喚了。\n" NOR);
	me->receive_wound("qi", 50,"體內怪蛇之毒發作");
	if(userp(me)) me->receive_wound("jing", 60,"體內怪蛇之毒發作");
	else me->receive_wound("jing", 80,"體內怪蛇之毒發作");
	if( me->query("jing") > 301)
		tell_room(environment(me),YEL+me->name()+"突然只膝彎曲，身子慢慢垂下，口中發出似人似獸的荷荷之聲。\n" NOR, ({ me }));
	else
		if( me->query("jing") < 450 && me->query("jing") > 301)
			tell_room(environment(me),BLU+me->name()+"忽然滿面堆歡裂嘴嘻笑，更顯得詭異無倫。\n" NOR, ({ me }));
		else
			if( me->query("jing") < 300 && me->query("jing") > 201)
				tell_room(environment(me),HIB+me->name()+"此時神智更加胡塗，指東打西，亂□亂咬。\n" NOR,({ me }));
			else tell_room(environment(me), HIR+me->name()+"突然縮成一團，滾在地上不停地發顫。\n" NOR,({ me }));
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("bt_poison", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
