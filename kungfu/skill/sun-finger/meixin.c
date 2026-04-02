// meixin.c 一陽指 「眉心指」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "眉心指"
int perform(object me, object target)
{
	string msg;
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
		
	if((int)me->query_str() < 28)
		return notify_fail("你膂力不夠，不能使用這一絕技！\n");

	if ( me->query_temp("weapon"))
		return notify_fail("你只能空手出「眉心指」。\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 &&
			(int)me->query_skill("kurong-changong",1) < 90 &&
			(int)me->query_skill("xiantian-qigong",1) < 90)
		return notify_fail("你的內功修為不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(sskill)+"修為不夠，不能出手"+PNAME+"。\n");

	if((int)me->query("max_neili") < 850)
		return notify_fail("你內力修為不夠，不能使用眉心指！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你內力現在不夠，不能使用眉心指！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顧不暇，放膽攻擊吧ⅵ\n");

	msg = HIR "$N"HIR"突然一躍而起，使出「眉心指」，點向$n"HIR"的眉心, 使$n"HIR"大驚失色。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if ((int)target->query_skill("hamagong",1)>100)
		{
			msg += HIY "$p大驚之下不及運功抵禦，$P一擊而中，正點在$p的眉心，破了$p多年苦練的蛤蟆功。\n"NOR;
			target->set("neili",100);
			target->receive_wound("jing",400,me);
			target->start_busy(random(3) + 1);
			me->start_busy(random(3) + 1);
			me->add("neili", -500);
		} else {
			msg += HIG"眉心指雖然點中，但是隻帶來一些疼痛。 \n"NOR;
			target->receive_wound("qi",100,me);
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "可是$p看破了$P的企圖，並沒有上當。\n" NOR;
		me->add("neili", -200);
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
		傷敵氣血

	出手要求：
		先天氣功或枯榮禪功90級
		一陽指90級
		內力850
		後天膂力28
HELP
	);
	return 1;
}

