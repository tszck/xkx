// sunxin.c 損心訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「" HIR "損心訣" NOR "」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, attack_decrease;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必須空手才能使用「損心訣」。\n");

	fskill = "jiuyang-shengong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不足，不能隨便使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"的修爲不夠，不能夠體會"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(bskill)+"還不到家，無法體現七傷拳的"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的內力還不夠高！\n");

	skill = me->query_skill(bskill,1) + me->query_skill("force",1);

	msg = HIY"$N凝神定氣，使出七傷拳總訣中的「" HIR "損心訣" HIY "」，雙拳勢如雷霆，向$n擊去。\n"NOR;
	message_combatd(msg, me, target);

	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 4;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-500);
		msg = HIG "$N連環拳勢如風雷，$n"HIG"中了$N"HIG"開山裂石的一拳，頓時心神大震，不能隨意出招！\n"NOR;
		attack_decrease = (int)target->query("apply/attack") ;
		if (attack_decrease > 0)
		target->add_temp("apply/attack", -attack_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		msg = HIG "只見$n"HIG"不慌不忙，輕輕一閃，躲過了$N"HIG"的必殺一擊！\n"NOR;
		if(userp(me)) me->add("neili",-200);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損害對手的攻擊能力

	出手要求：
		九陽神功60級
		基本拳法60級
		七傷拳60級
		內力500
HELP
	);
	return 1;
}


