// tougu.c 透骨針
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「透骨針」"
int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
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
		
	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("對方沒有兵刃，你不用使透骨針。\n");

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

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使"+PNAME+"。\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的內力不夠，無法使出"PNAME"！\n");
 
	skill = me->query_skill(bskill,1);
	msg = CYN"$N"CYN"使運出“透骨針”的內勁，$n"CYN"只覺得一股極陰寒的內力，貯於一點，從"+weapon->query("name")+CYN+"上傳來，攻堅而入。\n"HIR;

	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") / 1000;
	dp = target->query("combat_exp") / 2000;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili", -100);
		msg="$n胸口一痛，似乎被一枚極細的尖針刺了一下, 刺痛直鑽入心肺，
手一鬆，"+weapon2->query("name")+"便被"+weapon->query("name")+"吸了過去。\n"NOR;
		target->start_busy(random(2));
		target->receive_damage("qi", skill+random(skill/2));
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
		msg = HIY"$n猝遇大變，心神不亂，飛起旋風腿，攻向$N, $N後躍避開。\n"NOR;
		me->start_busy(3);
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
		劫奪對方兵器

	出手要求：
		聖火令法100級
		九陽神功100級
		內力300
		使用聖火令
HELP
	);
	return 1;
}

