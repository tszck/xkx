// yinfeng.c 陰風刀
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「陰風刀」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, damage;


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
		(string)weapon->query("id") != "shenghuo ling" ||
		weapon->query("ownmake") == 1)
		return notify_fail("你沒用聖火令，不能使用絕招！\n");

	fskill = "jiuyang-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使"+PNAME+"。\n");

	if( me->query("neili") < 500 )
		return notify_fail("你的內力不夠，無法使出陰風刀！\n");
 	skill = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"突然使出“陰風刀”，一股陰勁如刀、如劍、如匕、如鑿，直插入
$n胸口的“玉堂穴”中, 利如鋼刃。\n"NOR;

	message_combatd(msg, me, target);
	ap = me->query("combat_exp") / 2000;
	dp = target->query("combat_exp") / 3000;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili", -300);
		msg=HIG"$n霎時之間閉氣窒息，全身動彈不得。\n"NOR;
		target->start_busy(3+random(2));
		target->receive_damage("qi", skill+random(skill));
		me->start_busy(1);
	}
	else
	{
		msg = HIY"$n一聲清嘯, 飛身後躍相避。氣提丹田, 內力頓生。\n"NOR;
		me->start_busy(2);
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
		損傷對方氣血
		遲滯對方出手

	出手要求：
		聖火令法120級
		九陽神功120級
		內力500
		使用聖火令
HELP
	);
	return 1;
}

