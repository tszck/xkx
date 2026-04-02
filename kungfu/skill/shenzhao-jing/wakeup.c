// wakeup.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("can_perform/shenzhao-jing/wakeup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if ( !target || !target->is_character() )
		return notify_fail("你要用真氣救醒誰？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("戰鬥中無法運功救人！\n");

	if(target == me)
		return notify_fail("你不能為自己救醒自己！\n");

	if(!target->query_temp("noliving/unconcious") )
		return notify_fail("你只能救醒昏迷不醒的人！\n");

	if(!userp(target))
		return notify_fail("你只能救醒玩家！\n");

	if( (int)me->query_skill("shenzhao-jing", 1) < 100 )
		return notify_fail("你的神照經修為不夠。\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的內力修為不夠。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真氣不夠。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() + "已經受傷過重，經受不起你的真氣震盪！\n");

	message_combatd(HIY"$N坐了下來運起神照經內功，將手掌貼在$n背心，緩緩地將真氣輸入$n體內....\n\n過了不久，$n慢慢的甦醒過來。\n" NOR, me, target );

//	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
//	target->add("qi", 10 + (int)me->query_skill("force")/3 );
//	if( (int)target->query("qi") > (int)target->query("eff_qi") )
//		target->set("qi", (int)target->query("eff_qi"));

	target->remove_call_out("revive");
	target->revive();
	target->reincarnate();
 
	me->add("neili", -150);
	me->set("jiali", 0);
	me->start_busy(5);
	target->start_busy(5);
	return 1;
}
int help(object me)
{
	write(WHT"\n神照經之喚醒"NOR"\n");
	write(@HELP

	使用功效：
		喚醒昏迷中的他人

	出手要求：
		神照經100級
		內力1000
HELP
	);
	return 1;
}

