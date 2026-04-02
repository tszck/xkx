// shengang.c 混天氣功混天神罡
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/shengang") &&
  !me->query("can_perform/huntian-qigong/shengong") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( (int)me->query_temp("shengang") ) 
		return notify_fail(HIG"你已經在運混天神罡了。\n"NOR);

//	if( !me->is_fighting() )
//		return notify_fail("「混天神罡」只能在戰鬥中使用。\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的內力還不夠！\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 150)
		return notify_fail("你的混天氣功的修為不夠，不能使用混天神罡! \n");
//必須有兵器。加兵器威力
	msg = HIY "$N使出混天氣功「混天神罡」，將真氣貫注到手心！\n" NOR;

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("huntian-qigong",1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
		message_combatd(msg, me, target);
		me->add_temp("apply/damage", skill*2);
		me->set_temp("shengang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

		me->add("neili", -150);
	}
	else
	{
		msg = HIR"$N拼盡畢生功力想提起混天神罡，但自己受傷太重，沒能成功！\n" NOR;
	}
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("shengang") ) 
	{
		me->add_temp("apply/damage", - amount);
		me->delete_temp("shengang");
		tell_object(me, HIY "你的混天神罡運行完畢，將內力收回丹田。\n" NOR);
		me->start_busy(random(4));
	}
}
int help(object me)
{
	write(WHT"\n混天氣功之混天神罡："NOR"\n");
	write(@HELP

	使用功效：
		加重自己的出手威力

	出手要求：
		混天氣功150級
		內力400
HELP
	);
	return 1;
}

