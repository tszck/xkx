// weizun.c  五嶽爲尊
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「五嶽爲尊」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound,attack_time,i;
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

	fskill = "panshi-shengong";
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
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"修爲不夠, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的內力不夠，無法運用五嶽爲尊！\n");

	if( me->query("max_neili") < 400 )
		return notify_fail("你的內力修爲不夠，無法運用五嶽爲尊！\n");

	skill = me->query_skill(bskill,1);
	message_combatd(HIW"$N使出泰山劍法的「五嶽爲尊」，身法陡然加快，劍鋒一轉，從五個方向連出數劍！\n" NOR, me, target);

	me->add("neili", -100);
	attack_time = 3 + random(3);
	for(i = 0; i < attack_time; i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	}
	me->start_busy(2+random(3));
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		連續出手五劍

	出手要求：
		磐石神功50級
		泰山劍法60級
		內力修爲400
		內力300
HELP
	);
	return 1;
}


