// recover.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
//inherit SSERVER;

int exert(object me, object target)
{
	int n, q;

	if (me != target)
		return notify_fail("你只能用內功調勻自己的氣息。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠。\n");

	q = (int)me->query("eff_qi") - (int)me->query("qi");
	if (q < 10)
		return notify_fail("你現在氣力充沛。\n");
	n = 100 * q / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		q = q * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("qi", q);
	
        message_combatd("$N深深吸了幾口氣，臉色看起來好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
int help(object me)
{
	write(WHT"\n基本內功之調勻氣血："NOR"\n");
	write(@HELP

	使用功效：
		恢復氣血自己損失

	出手要求：
		基本內功
		內力20
HELP
	);
	return 1;
}

