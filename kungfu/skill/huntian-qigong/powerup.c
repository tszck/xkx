// powerup.c 混天氣功加力
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/huntian-qigong/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( target != me )
		return notify_fail("你只能用混天氣功來提升自己的戰鬥力。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的內力不夠。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已經在運功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR"$N微一凝神，運起混天氣功，全身骨節發出一陣爆豆般的聲響。\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "你的混天氣功運行完畢，將內力收回丹田。\n");
}

int help(object me)
{
	write(WHT"\n混天氣功之加力："NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻擊防禦能力

	出手要求：
			內力100
HELP
	);
	return 1;
}

