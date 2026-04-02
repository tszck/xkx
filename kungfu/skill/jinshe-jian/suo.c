// suo.c 鎖劍訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「鎖劍訣」"
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
//   !me->query("perform/"+pfname) &&
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
		(string)weapon->query("id") != "jinshe jian" ||
		weapon->query("ownmake") == 1)
		return notify_fail("你沒用金蛇劍，不能使用絕招！\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("對方沒有使用兵器，你用不了「鎖劍訣」。\n");
		
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( me->query("dex") < 20 || me->query("str") < 20 )
		return notify_fail("你的先天膂力身法孱弱, 不能使用"PNAME"！\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的內力不夠，無法運用"PNAME"！\n");

	skill = me->query_skill(bskill, 1);

	msg = HIC "$N"HIC"手中"YEL"金蛇劍"HIC"畫出一道金光，斜刺一拉，「鎖劍訣」！
"YEL"金蛇劍"HIC"劍尖倒鈎正好掛在$n"HIC"的"+weapon2->name()+"上。\n";
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = skill;
	dp = target->query_skill("dodge")/2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > random(dp) )
	{
		if(userp(me)) me->add("neili",-50);
		msg = "$n頓時覺得眼前金光一閃，手腕一振，手中"+weapon2->name()+"脫手飛出！\n" NOR;
		me->start_busy(random(2));
		target->receive_damage("qi", damage,me);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me)) me->add("neili",-30);
		msg = "$n急運內力，將手中" + weapon2->name() + "斜斜順勢一送一搭，抽了回來。\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血
		遲滯對方出手
		鎖拿對方兵器

	出手要求：
		先天膂力20
		先天身法20
		金蛇劍法150級
		內力300
		使用金蛇劍
HELP
	);
	return 1;
}

