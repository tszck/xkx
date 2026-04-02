// anran.c 黯然神傷
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「"+BBLU"黯然神傷"NOR +"」"

int perform(object me, object target)
{
	int damage;
	string msg;
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

	fskill = "yunv-xinfa";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠熟練，不會使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 1500 )
		return notify_fail("你的內力不夠。\n");
//	if (!userp(me) && me->query("id")!="yang guo")
//	  return notify_fail("只有玩家和楊過可以用黯然神傷。\n");

	msg = HIB"$N"HIB"緊閉雙目，潸然淚下，神情恍惚，鵠立風中，驀地往前直僕，掌風帶起刺骨寒氣，如急風驟雨般向$n"HIB"奔襲而至！ \n"NOR;
	damage = (int)me->query_skill(bskill, 1)*4; 
	damage = damage + random(damage); 
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		me->start_busy(3);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -1000);
		msg += RED"$n"RED"無處可躲，被$N"RED"雙掌齊印胸口上，一口鮮血狂噴而出！\n"NOR;
	}
	else
	{
		me->start_busy(5);
		msg +=HIG"$n"HIG"大駭之下，急退數丈，才從掌風中逃身而出，只覺臉上被掌風颳得生疼。\n"NOR;
		target->receive_damage("qi",damage/10,me);
		target->receive_wound("qi",damage/20,me);
		me->add("neili", -500);
	}
	message_combatd(msg,me,target);
	if(userp(target)) target->fight_ob(me);
	else if( !target->is_killing(me) ) target->kill_ob(me);
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
		玉女心法150級
		黯然銷魂掌150級
		內力1500
HELP
	);
	return 1;
}

