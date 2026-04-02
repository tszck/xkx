// dian.c 石鼓打穴筆法「點」字訣
// Last Modified by sir 11.1.2001

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「點」字訣"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "dagger")
		return notify_fail("你使用的武器不對。\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧！\n");

	fskill = "kuihua-xinfa";
	bskill = "dagger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不嫺熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的內力不夠，不會使用「點」字訣。\n");

	msg = HIC"$N使出石鼓打穴筆法「點」字訣，捲起漫天筆影，向$n電射而去，帶着呼呼風聲點向$n的全身要穴。$n不及攻敵，拼力躲避，頓時動作大亂。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P手中兵器點中$p的大穴，$p只覺微微一麻，迅即行動如常。\n"NOR;
			me->start_busy(random(4) + 1);
			me->add("neili", -150);
		} else {
			msg +=  HIG "結果$p被$P點中幾處穴道，驚慌失措，呆在當場，不知如何應對！ \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill,1) / 30) + 2);
			me->add("neili", -150);
		}
	} else {
		msg +=HIY"可是$p看破了$P的企圖，鎮定逾恆，一振振開了$P的兵器，全神應對自如。\n" NOR;
		me->start_busy(1);
		me->add("neili", -50);
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
		葵花心法50級
		石鼓打穴筆法40級
		內力300
HELP
	);
	return 1;
}

