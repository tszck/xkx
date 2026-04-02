// reserve.c 蛤蟆功經脈倒轉
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill;
	string msg;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/reserve") &&
  !me->query("can_perform/hamagong/reserve") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

        if ( me->query("family/master_id") != "ouyang feng" )
		return notify_fail("你目前還沒有這個功力，小心走火入魔。\n");
		
	if( (int)me->query_skill("hamagong", 1) < 160 )
		return notify_fail("你的蛤蟆功不夠嫺熟，不會經脈倒轉。\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的內力不夠。\n");

	if( (int)me->query_temp("hmg_dzjm") ) 
		return notify_fail("你已經倒轉經脈了。\n");

	skill = me->query_skill("hamagong",1);
	msg = HIB "$N忽地雙手撐地倒立，逆運經脈，頓時內息暗生，防禦力大增。\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", -skill/6);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("hmg_dzjm", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/2 :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("hmg_dzjm");
	tell_object(me, HIY "你雙手一撐，一躍而起，將內力收回丹田。\n"NOR);
}
int help(object me)
{
	write(WHT"\n蛤蟆功之經脈倒轉："NOR"\n");
	write(@HELP

	使用功效：
		倒轉經脈，規避點穴

	出手要求：
		蛤蟆功160級
		內力200
HELP
	);
	return 1;
}


