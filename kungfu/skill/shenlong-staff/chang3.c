// chang3.c
// Last Modified by winder on Mar. 10 2000
// Last Modified by sir on 4/26/2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "唱仙法吼字決"
int perform(object me, object target)
{
	int skill, ap, dp,i,neili,damage;
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
		
	fskill = "dulong-dafa";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你已經唱得精疲力竭,內力不夠了。\n");

	neili = me->query("neili");	
	if( neili/2 + random(neili/2) < (int)target->query("neili")/10) 
		return notify_fail("敵人的內力比你高出太多，傷不了！\n");

	me->receive_damage("qi", 10);

	me->start_busy(random(5));

	message_combatd(HIY"$N深深地吸一囗氣，忽然仰天長嘯，高聲狂叫：不死神龍，唯我不敗！\n" NOR, me);

	damage = me->query("max_neili") / 5;
	ap = me->query_skill(bskill) * 2;
	dp = target->query_skill("force") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )	
	{
		target->receive_damage("jing", damage/2,me);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing", damage/3,me);
		target->receive_wound("qi", damage,me);
		if (userp(me)) me->add("neili", -500);
		message_combatd( HIR "$N只覺腦中一陣劇痛，金星亂冒，猶如有萬條金龍在眼前舞動。\n" NOR, target);
	}
	else
	{
		message_combatd(HIR "$N只覺腦中微痛，似乎受了一點輕傷。\n" NOR, target);
		target->receive_damage("jing", 50 ,me);
		target->receive_damage("qi", 50 ,me);
		target->receive_wound("qi", 10 ,me);
		if (userp(me)) me->add("neili", -250);
	}
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對手精氣和氣血

	出手要求：
		毒龍大法90級
		神龍杖法100級
		內力500
HELP
	);
	return 1;
}

