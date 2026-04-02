// transfer.c 轉內力
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	int force, trans;

	if( query_ip_name(target)==query_ip_name(me))
		return notify_fail("你只能將真氣傳給其他玩家。\n");

	if( !target || target==me ||
		!living(target) || target->query_temp("noliving") )
		return notify_fail("你要將真氣傳給哪位？\n");

	if(me->query_skill_mapped("force")!=target->query_skill_mapped("force"))
		return notify_fail(target->name()+"所使用的內功和你不同，不能傳內力。\n");

	if( (int)me->query("neili") <= (int)me->query("max_neili")/3 )
		return notify_fail("你的真氣不足。\n");

	if( (int)me->query("max_neili") <= (int)target->query("max_neili") )
		return notify_fail("你的真氣還不如人家多，傳不過去。\n");

	if ((int)target->query("neili") >= (int)target->query("max_neili")*2)
		return notify_fail("對方的真氣充沛，不需要你的真氣。\n");
  if (target->is_busy())
   return notify_fail("對方正忙着呢。\n");
	force = me->query("neili") - (me->query("max_neili")/3);

	if( (int)force/3 < 1 ) return notify_fail("你的真氣不足。\n");
	me->add("neili", -(int)force/3 );
	me->start_busy(3);
	if( (int)me->query("max_neili") <= (int)target->query("max_neili")*5/4 )
		me->add("max_neili", -1);

	message_combatd(HIW"$N一掌拍在$n背心，順勢運氣將體內真氣傳送過去。\n"NOR, me,target);
	target->add("neili", (int)force/3);
	target->start_busy(3);
	tell_object(target, HIW "你覺得一股熱氣從"+me->name()+"的手掌中傳了過來。\n" NOR);
	return 1;
}

int help(object me)
{
	write(WHT"\n基本內功之傳送內力："NOR"\n");
	write(@HELP

	使用功效：
		將自己的內力傳送到別人體內　
		若接受方內力上限達到傳送方的八成，將損耗傳送方內力上限

	出手要求：
		基本內功
		內力20
		雙方是不同的ip
		雙方修習同一種內功
		接受方最大內力小於傳送方
HELP
	);
	return 1;
}

