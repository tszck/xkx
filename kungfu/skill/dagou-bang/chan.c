// chan.c 打狗棒法「纏」字訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「纏」字訣"
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

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧。\n");

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
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠深厚，不會使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");
	if(me->query("max_neili") < 400)
		return notify_fail("你的內力修為不夠，不會使用"PNAME"。\n");
	if(me->query("neili") < 300)
		return notify_fail("你的內力修為不夠，不會使用"PNAME"。\n");
	msg = HIG"$N"HIG"使出打狗棒法「纏」字訣，棒頭在地下連點，連綿不絕地挑向$n"HIG"的小腿和腳踝。\n";

	me->start_busy(1);
	me->add("neili", -200);
	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2 )
	{
		msg += HIR " 結果$p被$P攻的蹦跳不停，手忙腳亂！\n" NOR;
		target->start_busy( (int)me->query_skill(bskill, 1) / 20 );
	} else {
		msg += "可是$p看破了$P的企圖，鎮定解招，一絲不亂。\n" NOR;
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
		混天氣功100級
		打狗棒法100級
		內力修為400
		內力300
HELP
	);
	return 1;
}

