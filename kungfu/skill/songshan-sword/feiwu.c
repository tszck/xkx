// Last Modified by Winder on May. 21 2001
// feiwu.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「飛舞」"
int perform(object me, object target)
{
	object weapon;
	int i,count;
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

	fskill = "hanbing-zhenqi";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"功力太淺，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"功力太淺，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"功力太淺，無法使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("你的內力修爲太淺，無法飛舞攻擊。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真氣不夠，無法飛舞攻擊。\n");
		
	if( me->query_temp("ss_feiwu") )
		return notify_fail("你剛使完「飛舞」，目前氣血翻湧，無法再次運用！\n");

	me->add("neili", -300);

	message_combatd(BLU"\n$N"BLU"突然長嘯一聲，運氣寒冰真氣，舉劍挺刺，在半空中劃出道道劍光，空中氣勁激盪，陣陣寒氣向$n"BLU"奔襲而去！\n" NOR,me, target);

	me->add_temp("apply/damage", 50);
	for(count=0;count<5;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	}
	me->add_temp("apply/damage", -50);
	me->set_temp("ss_feiwu", 1); 
	i = (int)me->query_skill(bskill, 1)/30;
	if( 15 - i <= 4) i = 4;
	call_out("remove_effect", i, me);
	me->start_busy(1);

	return 1;
}

void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("ss_feiwu");
	tell_object(me, HIG"\n你經過一段時間調氣養息，又可以使用「飛舞」了。\n"NOR); 
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		重手出手四劍

	出手要求：
		寒冰真氣120級
		嵩山劍法120級
		基本劍法120級
		內力修爲1500
		內力500
HELP
	);
	return 1;
}

