// tonggui.c 全真劍法 同歸劍法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「同歸劍法」"
int perform(object me, object target)
{
	object weapon;	
	string msg;
	int d_count, count, qi, maxqi, skill,damage;
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

	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("沒有劍在手怎麼能用同歸劍法？\n");
		
	fskill = "xiantian-qigong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 10 )
		return notify_fail("你的"+to_chinese(fskill)+"修為不夠，不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修為太淺，未領會"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的內力還不夠！\n");

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	if(qi > (maxqi * 0.4))
		return notify_fail("你現在的身體狀況無法激發同歸劍法！\n");

	skill = (int) (me->query_skill(bskill, 1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	msg = HIY"$N使出「同歸劍法」，劍氣縱橫，只攻不守，招招拼命，兇狠危險之至！\n" NOR;
	if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = target->query("qi");
		target->receive_damage("qi", damage-10,me);
		target->receive_wound("qi", damage-10,me);
		msg += HIC "$n疾忙斜躍，但劍急如電，只覺一陣鑽心劇痛，劍尖扎入胸前，鮮血飛濺！\n"NOR;
		me->set("neili",0);
	}
	else
	{
		me->start_busy(2);
		me->set("neili",100);
		msg += HIY"可是$n微微一笑，氣定神閒，身形輕變，閃過劍招。\n"NOR;
	}

	message_combatd(msg, me, target);
	if(userp(target)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		耗盡全部內力，出手一劍

	出手要求：
		先天氣功100級
		全真劍法150級
		內力500
HELP
	);
	return 1;
}

