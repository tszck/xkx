// jingheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
/*
	if ((!target) || target->query("id")!=me->query("id"))
		return notify_fail("你要用真氣爲誰護精？\n");
*/
  if ( userp(me) && !wizardp(me) && 
  !me->query("can_perform/shenzhao-jing/jingheal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (!target) target = me;

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("戰鬥中無法運功護精！\n");

	if( (int)me->query_skill("shenzhao-jing",1) < 50 )
		return notify_fail("你的神照經內功修爲不夠。\n");

	if( me->is_busy() )
		return notify_fail("你現在正忙着呢，哪有空運功？\n");

	if( target->is_busy())
		return notify_fail(target->name()+"現在正忙着呢！\n");

	if( (int)me->query("max_neili") < 200)
		return notify_fail("你的內力修爲不夠。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的真氣不夠。\n");

	if( (int)target->query("eff_jing") >= (int)target->query("max_jing"))
		return notify_fail("只有精氣受損才需要護精。\n");

	if( (int)target->query("eff_jing") < (int)target->query("max_jing") / 5)
		return notify_fail("精氣受損過重，經受不起真氣震盪！\n");

  if ( me != target)
	message_combatd( HIC "$N坐了下來運起神照經內功，將左手掌貼在$n後背命門，右掌捂住$n丹田，緩緩地將運轉真氣....\n\n"HIY "過了不久，$n額頭上冒出豆大的汗珠，臉上的疲憊模樣也減輕多了。\n" NOR, me, target);
  else 
 	message_combatd( HIC "$N坐了下來運起神照經內功，將左手掌貼在後背命門，右掌捂住丹田，緩緩地將運轉真氣....\n\n"HIY "過了不久，$N額頭上冒出豆大的汗珠，臉上的疲憊模樣也減輕多了。\n" NOR, me);

  
	target->receive_curing("jing", 10 + (int)me->query_skill("force")/2 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)me->query("eff_jing"));

	me->add("neili", -50);
	me->start_busy(3);
	target->start_busy(2);
	return 1;
}

int help(object me)
{
	write(WHT"\n神照經之療精"NOR"\n");
	write(@HELP

	使用功效：
		爲自己或他人護精

	出手要求：
		神照經50級
		內力200
HELP
	);
	return 1;
}

