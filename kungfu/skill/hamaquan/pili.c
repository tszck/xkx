// pili.c 霹靂無形
// Last Modified by winder on May. 15 2001

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define PNAME "「霹靂無形」"
inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon,ob;
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

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(PNAME"只能空手使用。\n");		
		
	fskill = "hamagong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 20 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠，無法使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真氣不夠！\n");
		
	extra = me->query_skill(bskill, 1);
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra/2);
	weapon = me->query_temp("weapon");

	msg = BLU"$N"BLU"腳踩蛤蟆步，落身於丈尺外，稍作停頓，突然握拳撲向$n"BLU"，猶如蒼天霹靂雷霆之式！" NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage",-extra/2);
	me->add("neili", -100);
	me->start_busy(1);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		大力出拳

	出手要求：
		蛤蟆功50級
		蛤蟆拳20級
		內力100
HELP
	);
	return 1;
}

