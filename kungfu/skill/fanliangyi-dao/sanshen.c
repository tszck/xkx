// sanshen.c 華嶽三神峯
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define PNAME "「華嶽三神峯」"
inherit F_SSERVER;
 
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");

	fskill = "zixia-shengong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"功力不足，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"還不到家，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(bskill)+"還不到家，無法使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真氣不夠！\n");
	msg = HIY "$N"HIY"使出華山派絕技「華嶽三神峯」，身法突地變得異常靈動飄忽！\n" NOR;
	message_combatd(msg, me);

	for (count=0;count<3;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	}

	me->add("neili", -100);
	me->start_busy(random(3));

	if(!ob->is_fighting(me)) ob->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		連續出手三刀

	出手要求：
		紫霞神功80級
		基本刀法50級
		反兩儀刀法50級
		內力100
HELP
	);
	return 1;
}

