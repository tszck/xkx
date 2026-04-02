// yingzhang.c 刀影掌
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「刀影掌」"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
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
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("「刀影掌」開始時必須拿着一把刀！\n");

	fskill = "shenyuan-gong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠！無法使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠熟練！無法使出"+PNAME+"。\n");
	
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"還不到家，無法使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("xingyi-strike",1) < 100 )
			return notify_fail("你的星移掌不夠精通！無法使出「刀影掌」！\n");
		if( (int)me->query_skill("strike",1) < 100 )
			return notify_fail("你的基本掌法修為不夠！無法使出「刀影掌」！\n");
	}

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真氣不夠！\n");

	msg = HIC
"$N一聲長嘯，手中"+weapon->query("name")+HIC"頓時泛出一股殺氣，"HIR"刀影掌"HIC"！剎那間
殺氣如狂風湧到,把對手罩在一圈光幕之中。 \n" NOR;
	message_combatd(msg, me, ob);
//	me->clean_up_enemy();
//	ob = me->select_opponent();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add("neili", -50);
	me->start_busy(random(2));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		連續出手兩刀

	出手要求：
		神元功100級
		基本刀法100級
		慕容刀法100級
		基本掌法100級
		星移掌100級
		內力100
HELP
	);
	return 1;
}

