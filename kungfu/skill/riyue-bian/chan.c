// chan.c 日月鞭法「纏繞」訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「纏繞」訣"
int perform(object me, object target)
{
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
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不對。\n");

	fskill = "hunyuan-yiqi";
	bskill = "whip";
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

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠，使不出"+PNAME+"。\n");

	if (me->query("neili") < 300 )
		return notify_fail("你的內力不足，使不出「纏繞」訣。\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧！\n");

	msg = CYN"$N使出日月鞭法「纏繞」訣，連揮數鞭企圖把$n"CYN"的全身纏繞起來。\n";

	me->start_busy(random(3));
	me->add("neili", -100);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		msg += "結果$p被$P攻了個措手不及！\n" NOR;
	        target->start_busy( (int)me->query_skill("whip", 1) / 30);
	} else {
		msg += "可是$p看破了$P的企圖，並沒有上當。\n" NOR;
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
		遲滯對方出手

	出手要求：
		混元一氣功60級
		日月鞭法60級
		內力300
HELP
	);
	return 1;
}

