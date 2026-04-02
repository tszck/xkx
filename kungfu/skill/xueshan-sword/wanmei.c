// Last Modified by winder on Jul. 9 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「"+HIW"萬梅飄零"NOR+"」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int neili_wound, qi_wound;
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

	fskill = "bingxue-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"修為不夠, 不能使用"+PNAME+"。\n");

	if( me->query("max_neili") < 400 )
		return notify_fail("你的內力修為不夠，無法運用「"+HIW"萬梅飄零"NOR+"」！\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的內力不夠，無法運用「"+HIW"萬梅飄零"NOR+"」！\n");

	msg = HIW"$N長嘯一聲，使出「萬梅飄零」，手中兵器疾卷，掀起萬朵雪花向前鋪天蓋地地撒去。\n在白茫茫的一片中，忽然出現萬朵梅花形劍花，穿透雪幕，朝四面八方狂射而出。\n" NOR;
	message_combatd(msg, me, target);

	if( random(me->query_skill("force"))>target->query_skill("force")/2 || 
		random(me->query("combat_exp"))>target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(2+random(2));
		qi_wound = me->query_skill(bskill, 1);
		qi_wound = qi_wound + random(qi_wound/2);
		target->receive_damage("qi", qi_wound/2,me);
		target->receive_wound("qi", qi_wound,me);
		target->receive_damage("jing", qi_wound,me);
		target->receive_wound("jing", qi_wound/2,me);
		if(userp(me)) me->add("neili",-300); 
		msg = HIC"無數梅花光華，幻出道道劍氣，將$n全身上下罩得嚴嚴實實。$n身在其中，\n只覺劍光束束，在自己身上絲絲劃過，一時全身劇痛，鮮血飛濺得到處都是。\n如同凌遲之刑，慘不堪言。\n" NOR; 
  	message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg = "可是$n輕捷地往旁邊一閃，避過了這一劍。\n"NOR;
  	message_combatd(msg, me, target);
		me->start_busy(2);
	}
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		傷害對方精氣和氣血

	出手要求：
		冰雪心法80級
		雪山劍法80級
		內力修為400
		內力300
HELP
        );
        return 1;
}


