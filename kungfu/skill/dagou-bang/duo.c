// duo.c 獒口奪杖
// Last Modified by winder on Nov. 16 2000
 
#include <ansi.h>
inherit F_SSERVER;
#define PNAME "獒口奪杖"
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

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("對方沒有兵刃，你不用擔心。\n");

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
	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠, 不能"+PNAME+"。\n");
	if( !me->query_temp("murong/xingyi") )
	{
		if ((int)me->query_skill("dagou-bang",1)< 50)
			return notify_fail("你打狗棒法火候不夠, 不能獒口奪杖！\n");
		if ((int)me->query_skill("huntian-qigong",1) < 50)
			return notify_fail("你混天氣功火候不夠，使不出獒口奪杖。\n");
	}
	if(me->query("max_neili") < 300)
		return notify_fail("你的內力修爲不夠，不會使用獒口奪杖。\n");
	if(me->query("neili") < 200 )
		return notify_fail("你的內力不夠，無法獒口奪杖！\n");
 
	skill = me->query_skill(bskill,1);
	msg = HIY"$N"HIY"和身向前撲出，左手手指已搭住"+weapon2->query("name")+HIY"。\n";
	message_combatd(msg, me);
 
	dp = (int) (target->query_skill("parry", 1)/3);
	if( random(skill) > dp )
	{
		if(userp(me)) me->add("neili", -150);
		msg = HIG"$n"HIG"斗然見$N"HIG"猶似飛將軍從天而降，猛喫一驚，舉起"+weapon2->query("name")+HIG"待擊，\n$N"HIG"右手食中二指倏取$n"HIG"的雙目，同時左足翻起，已將"+weapon2->query("name")+HIG"壓住！\n$n"HIG"爲保眼珠，只好撒手。\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if(weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "只聽一聲脆響！兵刃落地。\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = HIR"可是$n"HIR"手臂一振，將$N左手彈了開去。\n"NOR;
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
		混天氣功50級
		打狗棒法50級
		內力修爲300
		內力200
HELP
	);
	return 1;
}

