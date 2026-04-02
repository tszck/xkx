// huanying.c  雁行刀法「無形幻影」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「無形幻影」"
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int flag;
	int count;
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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail(RED"開什麼玩笑，沒裝備刀怎麼使「無形幻影」？\n"NOR);

	fskill = "linji-zhuang";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，"+PNAME+"不成招式。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");

	if ((int)me->query("max_neili")<300)
		return notify_fail(RED"你的內力修為不足，無法運足「無形幻影」的內力。\n"NOR);

	if ((int)me->query("neili")<200)
		return notify_fail(HIC"你現在內力不夠，沒能將「無形幻影」使完！\n"NOR);

	msg=HIC "$N大喝一聲，全場四處遊動，$n只看到$N化做數團身影，漫天刀\n"NOR;
	msg += HIC"光席捲而來，$n奮力一架，但$N刀分數路，$n只架住一刀！\n"NOR;
	message_combatd(msg, me, target);

	for(count=0;count<5;count++)
	{
		if (flag == 1)target = offensive_target(me);
		if (!objectp(target)) break;
 		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
 	}
	me->add("neili", -100);
	me->start_busy(random(5));
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		連續出手五刀

	出手要求：
		臨濟十二莊90級
		雁行刀法60級
		內力300
HELP
	);
	return 1;
}

