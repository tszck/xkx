// poqi.c 破氣式
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	if(me->query("family/master_id") != "feng qingyang" && userp(me))
		return notify_fail("你不是風清揚的弟子，不能使用絕招！\n");
	skill = me->query_skill("lonely-sword",1);
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/poqi") &&
  !me->query("can_perform/lonely-sword/poqi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中沒有這種功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("「破氣式」只能對戰鬥中的對手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");
	if( skill < 100)
		return notify_fail("你的獨孤九劍等級不夠, 不能使用破氣式！\n");
	if( me->query("max_neili") < 500 )
		return notify_fail("你的內力修爲不夠，無法運用「破氣式」！\n");
	if( me->query("neili") < 250 )
		return notify_fail("你的內力不夠，無法運用「破氣式」！\n");
	msg = HIC "$N潛運獨孤九劍「破氣式」，運氣貫劍使其由利返鈍，毫無花俏地直
刺$n的丹田。\n";
	message_combatd(msg, me, target);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-150);
		msg ="$N運起「破氣式」，長劍斜挑對方小腹，$n頓時覺得眼前一花，氣海穴\n上微微一痛，全身真氣狂泄而出！\n" NOR;
		neili_wound = 300 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		qi_wound = skill+(int)me->query_skill("sword",1)/2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi")) qi_wound = 100;
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->set_temp("lonely-sword/poqi",1);
		target->start_busy(2);
		me->start_busy(2);
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg = "可是$n看破了$N的企圖，立刻守緊門戶，幾經艱難終於還招擋開。\n"NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	return 1;
}
int help(object me)
{
	write(WHT"\n獨孤九劍之破氣式："NOR"\n");
	write(@HELP

	使用功效：
		破解身具高深內功的敵手之武功，並傷敵氣血

	出手要求：
		身爲風清揚嫡傳弟子
		獨孤九劍100級
		內力修爲500
		內力250
HELP
	);
	return 1;
}

