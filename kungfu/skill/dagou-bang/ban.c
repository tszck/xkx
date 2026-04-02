// ban.c 打狗棒法「絆」字訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「絆」字訣"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
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

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "stick")
			return notify_fail("你使用的武器不對。\n");

//	if( target->is_busy() )
//		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧ⅵ\n");
	fskill = "huntian-qigong";
	bskill = "stick";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠深厚，不會使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");
	if(me->query("max_neili") < 800)
		return notify_fail("你的內力修為不夠，不會使用"PNAME"。\n");
	if(me->query("neili") < 400)
		return notify_fail("你的內力修為不夠，不會使用"PNAME"。\n");
	msg = HIY "$N"+weapon->name()+HIY"一幌，$n"HIY"急忙躍起，雙足離地半尺，\n";
 
	me->start_busy(2);
	me->add("neili", -200);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		msg += HIR "剛好棒兒一絆，輕輕巧巧的便將$n"HIR"絆倒了。\n" NOR;
		target->receive_damage("qi", 200,me);
		target->receive_damage("jing", 200,me);
		target->start_busy(3);
	} else {
		msg += HIG"可是$n"HIG"全神留心下盤，只待"+weapon->name()+HIG"伸來，立即上躍，教$N"HIG"絆之不著。\n" NOR;
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
        損耗對方的氣血與精氣

	出手要求：
		混天氣功120級
		打狗棒法120級
		內力修為800
		內力400
HELP
	);
	return 1;
}

