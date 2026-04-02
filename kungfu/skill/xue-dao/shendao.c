// shendao.c  血刀「祭血神刀」

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「祭血神刀」"
int perform(object me, object target)
{
	int damage, power;
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail(RED"裝備刀才能使用"PNAME"？\n"NOR);

	fskill = "longxiang";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");

	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"你內力修爲不足，無法運足內力。\n"NOR);

	if ((int)me->query("neili") < 600)
		return notify_fail(HIC"你現在內力不夠，沒能將「祭血神刀」使完！\n"NOR);

	msg = HIR"$N右手持刀向左肩一勒，一陣血珠濺滿刀面，緊接着右臂掄出，一片
血光裹住刀影向$n當頭劈落，\n"NOR;
	if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		if ((int)me->query("shen") <= -100000) power = -100000;
		else if ((int)me->query("shen") < -1000 && 
			(int)me->query("shen")>-100000)
			power = (int)me->query("shen");
		else power = -1000;

		damage =random((int)(power/-100))+(int)(power/-200);
		me->add("neili", -600);
		me->receive_wound("qi", me->query("qi")/10);
		me->start_busy(3);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
msg += HIR"$n疾忙側身避讓，但血刀疾閃，只覺眼前一陣血紅，刀刃劈面而下，鮮血飛
濺，慘聲大嚎！\n"NOR;
	} else
	{
		me->start_busy(2);
		me->receive_wound("qi", me->query("qi")/20);
msg += HIY"可是$n側身避讓，不慌不忙，躲過了$N的血刀。\n"NOR;
		me->add("neili", -200);
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
		先傷己，再傷人
		損傷對方氣血

	出手要求：
		龍象般若功60級
		血刀刀法100級
		內力600
HELP
	);
	return 1;
}

