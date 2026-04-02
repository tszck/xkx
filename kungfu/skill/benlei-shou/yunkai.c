// yunkai.c 雲開霧闔
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「雲開霧闔」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;

	int flag;
	string fskill,sskill,bskill,pfname;

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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能使用"PNAME"！\n");
		
	fskill = "honghua-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠，不能使用"+PNAME+"。\n");
	if( me->query("max_neili") < 200 )
		return notify_fail("你的內力修為不夠，無法使"PNAME"！\n");
	if( me->query("neili") < 150 )
		return notify_fail("你的內力不夠，無法運用"PNAME"！\n");
 
	msg = HIC "$N"HIC"潛運「雲開霧闔」，雙掌挾着陣陣的風雷之聲向$n"HIC"擊去。\n"NOR;
	message_combatd(msg, me, target);
	skill = me->query_skill(bskill, 1);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		msg=HIR"$n"HIR"只覺得胸前一陣劇痛，“哇”的一聲噴出一口鮮血！\n"NOR;
		neili_wound = 100 + random(skill);
		qi_wound = neili_wound * 2;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		if(userp(me)) me->add("neili",-(100+neili_wound/2));
		
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG"只見$n不慌不忙，輕輕一閃，躲過了$N的必殺一擊！\n"NOR;
		if(userp(me)) me->add("neili",-100);
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
		傷害對方氣血和內力

	出手要求：
		紅花神功60級
		奔雷手60級
		內力修為200
		內力150
HELP
	);
	return 1;
}

