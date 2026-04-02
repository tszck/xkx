// sansha.c 三記殺招
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「三記殺招」"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
 	int i;
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
	if( (int)me->query_skill(fskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(fskill)+"功力不足，無法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"還不到家，無法使用"+PNAME+"。\n");
	if( (int)me->query("max_neili") < 800 )
		return notify_fail("你的內力修為不夠！\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真氣不夠！\n");
	msg = HIY "$N"HIY"一聲低吼，連續使出打狗棒法「三記殺招」！\n" NOR;
	message_combatd(msg, me);

	count = (int)(me->query_skill(bskill,1)/10);
	me->add("neili", -500);
	me->set_temp("apply/strength", count * 2);
	me->set_temp("apply/dexerity", 0-count);

	for(i=0;i<3;i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}

	me->start_busy(1);
	me->add_temp("apply/strength", -count*2);
	me->add_temp("apply/dexerity",  count);

//	if(!target->is_fighting(me)) target->fight_ob(me);
	if(flag != 1) target->fight_ob(me);
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
		混天氣功200級
		打狗棒法200級
		內力修為800
		內力600
HELP
	);
	return 1;
}

