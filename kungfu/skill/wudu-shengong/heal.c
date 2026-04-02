// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/heal") &&
  !me->query("can_perform/wudu-shengong/heal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( me->is_fighting() )
		return notify_fail("戰鬥中運功療傷？找死嗎？\n");

	if( me->is_busy() )
		return notify_fail("你現在正忙着呢，哪有空運功？\n");

	if( (int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("你的五毒神功修爲還不夠。\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真氣不夠。\n");
/*
	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail(HIR"你沒有受傷，不必運真氣療傷！\n"NOR);
*/
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("你已經受傷過重，只怕一運真氣便有生命危險！\n
");

	write( HIW "你全身放鬆，五毒神功流轉全身。\n" NOR);
	message("vision", HIW + me->name() + "面頰現出一片潮紅，額頭上沁出細細的汗珠。\n" NOR, environment(me), me);
	me->set_temp("nopoison", 1);
	me->clear_condition("snake_poison");
	me->clear_condition("wugong_poison");
	me->clear_condition("xiezi_poison");
	me->clear_condition("zhizhu_poison");
	me->clear_condition("chanchu_poison");
	me->clear_condition("scorpion_poison");
	me->clear_condition("ice_poison",0);
	write( HIW "你輕輕呼出一口氣，將真氣收歸丹田，感覺精神好多了。\n" NOR);
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(1);
	return 1;
}
int help(object me)
{
	write(WHT"\n五毒神功之自療："NOR"\n");
	write(@HELP

	使用功效：
		爲自己療傷
		解除本門之毒

	出手要求：
		五毒神功20級
		內力50
HELP
	);
	return 1;
}

