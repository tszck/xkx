// tianwai.c 天外清音
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「天外清音」"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");

	fskill = "bibo-shengong";
	bskill = "sword";

	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");

	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	skill = me->query_skill("sword", 1);

	if( me->query("neili") < 250 )
		return notify_fail("你的內力不夠，無法運用「天外清音」！\n");

	msg = HIC "$N一聲清嘯，劍發琴音，深吸一口氣，劍附內力，一式「天外清音」，"+weapon->name()+HIC+"閃動不止，劍影如夜幕般撲向$n。\n";
	message_combatd(msg, me, target);

	ap = 2 * skill;
	dp = target->query_skill("force", 1) / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-150);
		msg ="$n頓時覺得眼前金光亂閃動，雙耳嗡嗡內鳴，不知那裏一陣刺痛如針扎一般！\n" NOR;
		qi_wound = 2 * skill;
		qi_wound = qi_wound/2 + random(qi_wound);
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
		me->start_busy(1+random(3));
	}
	else
	{
		if(userp(me)) me->add("neili", -100);
		msg = "可是$n寧心靜氣，隨手揮灑，將$N的招數撇在一邊。\n"NOR;
		me->start_busy(2+random(3));
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

	出手要求：
		碧波神功120級
		玉簫劍法90級
		內力250
HELP
	);
	return 1;
}

