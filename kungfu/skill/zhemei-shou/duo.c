// duo.c 空手入白刃
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h> 

inherit F_SSERVER;
#define PNAME "空手入白刃"
int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
	int skill, dp, damage;
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

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必須空手。\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("對方沒有兵刃，你不用擔心。\n");

	fskill = "beiming-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠, 不能"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠, 不能"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(bskill)+"火候不夠, 不能"+PNAME+"。\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的內力不夠，無法空手入白刃！\n");

	skill = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"凝神閉息，打算施展空手入白刃的絕技。\n";
	message_combatd(msg, me);
 
	dp = target->query_skill("parry", 1);
	if( dp < 1 )
		dp = 1;
	if (fam_type(me)=="xiaoyao") dp /= 2;
	if( random(skill) > dp *4/5)
	{
		me->add("neili",-50);
		msg ="$N使出空手入白刃的絕招, $n頓時覺得眼前一花，手腕一麻，手中兵刃脫手而出！\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if (weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "只聽一聲脆響！兵刃落地。\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = "可是$n的看破了$N的企圖，立刻採取守勢，使$N沒能奪下兵刃。\n"NOR;
		me->start_busy(4);
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
		劫奪對方兵刃

	出手要求：
		北冥神功50級
		天山折梅手50級
		基本手法50級
		內力50
HELP
	);
	return 1;
}

