// tianlei.c 鐵掌掌法 「天雷氣」
// Last Modified by winder on Aug. 28 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「天雷氣」"
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
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
		return notify_fail("你必須空手才能使用天雷氣！\n");

	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"還未練成，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你現在內力不足，不能使用天雷氣！\n");	
	msg = HIY"\n$N忽然仰天大喝一聲“天 雷 氣”，雙掌如風車般連環擊出，一陣熱浪隨掌勢狂飆而出，勢不可擋！\n"NOR;

	if( weapon = target->query_temp("weapon") )
	{
		if( random(me->query_str()) > (int)target->query_str()/2 )
		{
			msg +=HIM"\n$p只覺得渾身一熱，手掌虎口巨痛，手中" + weapon->query("name") + HIM+"脫手而出。\n" NOR;
			message_combatd(msg, me, target);
			(target->query_temp("weapon"))->move(environment(target));
		}
		else
		{
			msg +=HIY"\n$p危急中突然伏地翻滾而出，避過了這致命一擊，已嚇得臉色蒼白！\n" NOR;
			message_combatd(msg, me, target);
		}
		me->start_busy(1);
	}
	else
	{
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
			me->start_busy(3);
			target->start_busy(random(3));
			damage = (int)me->query_skill("force", 1);
			damage += (int)me->query_skill("strike", 1);
			damage = damage * 2 + random(damage);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage / 2,me);
			if( damage < 300 ) msg += HIY"\n結果$n臉色一下變得慘白，昏昏沉沉接連退了好幾步！\n"NOR;
			else if(damage < 400 ) msg += HIY"\n結果重重地擊中，$n「哇」地一聲吐出一口鮮血！\n"NOR;
				else if(damage < 500 ) msg += RED"\n結果「轟」地一聲，$n全身氣血倒流，口中鮮血狂噴而出！\n"NOR;
					else msg += HIR"\n結果只聽見幾聲喀喀輕響，$n一聲慘叫，像灘軟泥般塌了下去！！\n"NOR;
		}
		else 
		{
			me->start_busy(1);
			msg +=HIY"\n$p危急中突然伏地翻滾而出，避過了這致命一擊，已嚇得臉色蒼白！\n" NOR;
		}
		message_combatd(msg, me, target);
	}
	me->add("neili", -600);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		劫奪對方兵刃或傷害對方氣血

	出手要求：
		歸元吐納法120級
		鐵掌掌法120級
		上官劍南親傳弟子
		內力600
HELP
	);
	return 1;
}

