// chang2.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "唱仙法之哼字決"
int perform(object me, object target)
{
	int skill;
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

/*	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
*/	
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

	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if((int)me->query_temp("apply/attack") <= 0 ||
		(int)me->query_temp("apply/dodge") <= 0 ||
		(int)me->query_temp("apply/defense") <= 0)
		return notify_fail("你目前戰鬥力太低，不能再恢復內力了。\n");

	if( (int)me->query_temp("chang") <=-30 )
		return notify_fail("你已經唱得太久了，不能再唱了。\n");

	message_combatd(HIR "只聽$N"HIR"口中哼哼唧唧，頃刻之間內力大漲！\n" NOR, me);
	me->add_temp("apply/attack", -1);
	me->add_temp("apply/dodge", -1);
	me->add_temp("apply/defense", -1);
	me->add_temp("chang", -1);
	me->add("neili", 100);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		降低自己的攻擊力、防禦力
		增補自己的內力

	出手要求：
		毒龍大法70級
		神龍杖法80級
HELP
	);
	return 1;
}

