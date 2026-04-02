// shield.c 小無相功護體神功
// Last Modified by Winder on Oct. 20 2000
//

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/shield") &&
  !me->query("can_perform/xiaowuxiang/shield") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( target != me ) 
		return notify_fail("你只能用小無相功來提升自己的防禦力。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的內力不夠。\n");

	if( (int)me->query_skill("xiaowuxiang",1) < 40  ) 
		return notify_fail("你的小無相功修爲不夠。\n");

	if( (int)me->query_temp("shield") ) 
		return notify_fail("你已經在運功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(
	HIW "$N雙手平舉過頂，運起小無相功，全身籠罩在勁氣之中！\n" NOR, me);

	me->add_temp("apply/armor", skill);
	me->set_temp("shield", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");
	tell_object(me, "你的小無相功運行完畢，將內力收回丹田。\n");
}
int help(object me)
{
	write(WHT"\n小無相功之護體神功"NOR"\n");
	write(@HELP

	使用功效：
		增強自己的防護力

	出手要求：
		小無相功40級
		內力100
HELP
	);
	return 1;
}

