// wuji.c 混元無極
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「混元無極」"

int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	fskill = "zixia-shengong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的內力不夠，無法運用"PNAME"！\n");
 
	msg = HIC "$N"HIC"潛運「混元無極」，雙拳挾着隱隱的風雷之聲向$n"HIC"擊去。\n"NOR;
	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-100);
		msg =HIG"$n只覺得胸前一陣劇痛，“哇”的一聲噴出一口鮮血！\n"NOR;
		neili_wound = 100 + random(skill);
		qi_wound = neili_wound * 2;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_wound("qi", qi_wound,me);

		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		target->add("neili", -neili_wound);

		target->start_busy(2);
		me->start_busy(1+random(2));
	}
	else
	{
		msg = HIG "只見$n"HIG"不慌不忙，輕輕一閃，躲過了$N"HIG"的必殺一擊！\n"NOR;
		if(userp(me)) me->add("neili",-100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血
		遲滯對方出手

	出手要求：
		紫霞神功60級
		混元掌60級
		內力150
HELP
	);
	return 1;
}

