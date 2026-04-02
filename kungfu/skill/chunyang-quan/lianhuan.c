// lian.c 連環拳
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#define PNAME "「連環拳」"
inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg;
	int count;
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
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail(PNAME"不能持兵刃！\n");
		
	fskill = "xiantian-qigong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(sskill)+"還不到家，無法使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真氣不夠！\n");
	msg = HIY "$N"HIY"已然領悟了「先天純陽」之真義，「連環拳」出拳愈來愈急，毫
無停頓滯澀之感！\n" NOR;
	message_combatd(msg, me);
	
	for(count=0;count<3;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (objectp(target))		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}

	me->add("neili", -100);
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
		連續出手三招

	出手要求：
		先天氣功140級
		純陽拳135級
		內力100
HELP
	);
	return 1;
}

