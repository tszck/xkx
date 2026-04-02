// shenjian.c 桃花影裏飛神劍

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h"
#define PNAME "桃花影裏飛神劍"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, rand, p;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手使用桃花影裏飛神劍！\n");

	fskill = "bibo-shengong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，無法施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，無法使用"+PNAME+"。\n");

	if ( (int)me->query("neili") < 120)
		return notify_fail("你的內力不夠，無法使用桃花影裏飛神劍。\n");

	if (!me->query_temp("murong/xingyi"))
	{
		if (me->query_skill_prepared("strike") != "luoying-zhang" ||
			me->query_skill_mapped("strike") != "luoying-zhang")
			return notify_fail("你現在無法使用桃花影裏飛神劍進行攻擊！\n");
	}
	
	msg = CYN "\n$N雙掌豎起，默運碧海潮生功，掌緣便似劍鋒一樣發出絲絲的"GRN"劍氣"CYN"，分別從左右兩邊斬向$n！\n"NOR;
	rand = random(me->query("combat_exp"));
	if( rand > (int)target->query("combat_exp")/4 )
	{
		me->add("neili", -100);
		me->start_busy(2);
		damage = (int)me->query_skill(bskill, 1)*3/2;
		damage += random(damage);
//		if (damage > target->query("neili") / 8)
//			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "劈傷");
		msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else
	{
		me->add("neili", -50);
		me->start_busy(3);
		msg += HIY"$n大喫一驚，退步抽身，萬分驚險中堪堪躲過了這招，早已嚇出了一身冷汗！\n" NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對手氣血

	出手要求：
		落英神劍掌80級
		碧波神功80級
		內力120
HELP
	);
	return 1;
}

