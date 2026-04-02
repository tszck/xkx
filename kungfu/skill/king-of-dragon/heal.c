// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_busying() )
		return notify_fail("你現在正忙着呢，哪有空運功？\n");

	if ( !wizardp(me)) return 0 ;
	write( HIY "你全身放鬆，坐下來開始運功療傷。\n" NOR);
	message("vision", HIY + me->name() + "吐出一口金燦燦的血，臉色立刻恢復了正常。\n" NOR, environment(me), me);

	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("jingli", (int)me->query("max_jingli"));
	return 1;
}
