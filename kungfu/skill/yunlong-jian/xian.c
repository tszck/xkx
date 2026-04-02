// xian.c  雲龍三現
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「雲龍三現」"
int perform(object me, object target)
{
	object weapon;
	int damage;
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
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");

	fskill = "yunlong-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠高，不能用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你現在內力太弱，不能使用「雲龍三現」。\n");

	msg = CYN "$N微微一笑，猛吸一口氣，欲使出以氣馭劍絕技攻擊$n。\n"NOR;


	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		if (!target->is_busy())
		target->start_busy( (int)me->query_skill(bskill, 1) / 30 + 1);

		damage = (int)me->query_skill("force", 1);
		damage +=  2 * (int)me->query_skill("sword", 1);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -damage/2);
		msg += HIY "只見$N手中劍光幻作一條金龍，騰空而起，倏的罩向$n"HIY"，$n"HIY"只覺一股大力鋪天蓋地般壓來，登時眼前一花，兩耳轟鳴，哇的噴出一口"HIR"鮮血！！\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"可是$p猛地向後一躍，跳出了$P的攻擊範圍。\n"NOR;
		me->add("neili", -100);
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
		損傷對方氣血

	出手要求：
		雲龍神功50級
		雲龍劍法50級
		內力300
HELP
	);
	return 1;
}

