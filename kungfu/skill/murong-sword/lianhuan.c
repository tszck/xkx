// lianhuan.c 連環
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「七劍連環」"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count,attack_time,i;
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
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「七劍連環」開始時必須拿着一把劍！\n");

	fskill = "shenyuan-gong";
	bskill = "sword";
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
		if( (int)me->query_skill("canhe-finger",1) < 100 )
			return notify_fail("你的參合指不夠精通！無法使出「七劍連環」！\n");
		if( (int)me->query_skill("finger",1) < 100 )
			return notify_fail("你的基本指法修爲不夠！無法使出「七劍連環」！\n");
	}

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真氣不夠！\n");

	msg = HIC "$N"HIC"運起慕容世家行雲流水，順其自然的心法，手中"+weapon->query("name")+ HIC"頓時鋒芒暴長，劍招連綿不絕湧上心頭，不可遏止，就在手中使了出來。瞬息之間，全身便如罩在一道光幕之中。\n" NOR;
	message_combatd(msg, me);
	attack_time = 6 + random(2);
	for(i = 0; i < attack_time; i++)
	{
		if (flag==1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	}
	me->add("neili", -50*i);
	me->start_busy(2+random(3));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		連續出手六七劍

	出手要求：
		神元功100級
		基本劍法100級
		慕容劍法100級
		基本指法100級
		參合指100級
		內力500
HELP
	);
	return 1;
}

