// cuixin.c 摧心訣 
// Last Modified by winder on Aug. 10 2000

#include <ansi.h>
#define PNAME "「摧心訣」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
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

//	if (me->query_temp("weapon") )
//		return notify_fail(PNAME"開始時不能拿着兵器！\n");

	//兵器空手均可

	fskill = "qingming-xuangong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");
	if ((int)me->query("neili")<400 || (int)me->query("max_neili")<400)
		return notify_fail(RED"你內力修爲不足，無法運足內力。\n"NOR);
	msg = HIG "$N"HIG"猛地一個側身一閃，轉到$n"HIG"身後，右掌往$n"HIG"後心印了下去，\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1) * 2;// if 300 strike
		damage = damage + random(damage);  //  damage 平均 900
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage*2/3,me);
		msg +=HIR"$n"HIR"疾忙轉身，卻已不及，後心一震只覺得喉頭一甜一條血絲從嘴角掛了下來！\n"NOR;
		me->add("neili", -damage/5);
	} else
	{
		me->start_busy(2);
		msg += HIY"可是$p也隨着轉身，避開了後心要害。\n"NOR;
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
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
		青冥玄功80級
		摧心掌100級
		內力400
HELP
	);
	return 1;
}

