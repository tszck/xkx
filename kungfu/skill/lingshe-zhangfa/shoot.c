// throw.c 靈蛇杖法噴毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "噴毒"

int perform(object me, object target)
{
	object weapon;
	string msg;
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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
  	return notify_fail("你要對誰噴毒? \n");

	if( environment(me)->query("no_fight") )
		return notify_fail("這裏不能攻擊別人！\n");
  notify_fail("你不能攻擊這個人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不對。\n");

	fskill = "hamagong";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不能"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不能"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("你的內力不夠，不能噴毒。\n");

	if( (string)weapon->query("id") != "she zhang" )
		return notify_fail("你手中沒有蛇杖，不能噴毒。\n");

	me->add("neili", -200);

	msg = MAG "$N"MAG"喉間發出刺耳的格格聲響，蛇杖前頭的小蛇猛地揚頭，一陣粉紅毒霧帶着甜香噴向$n"MAG"。\n";

	me->start_busy(1);

	if( random( (int)me->query_skill(bskill, 1)) >
		random(target->query_skill("dodge", 1)) )
	{
		msg += MAG "結果$p被$P杖頭小蛇一口噴中！\n" NOR;
		if (target->query("neili") < me->query("neili"))
		{
			msg += MAG "$p只聞到一陣甜香，眼前就模糊起來。\n" NOR;
			target->receive_damage("qi",(int)me->query_skill("staff", 1),me);
			target->receive_wound("qi",15 + random(10),me);
			target->receive_wound("jing", 10,me);
			target->apply_condition("snake_poison", random(me->query_skill(bskill, 1)/10) + 1 + target->query_condition("snake_poison"));
			target->start_busy(1 + random(2));
		}
		else
		{
			msg += CYN "$p急運內力，一口真氣向蛇毒噴去，頓時蛇毒反向$P飄了回去。\n" NOR;
			msg += MAG "$P只聞到一陣甜香，眼前就模糊起來。\n" NOR;
			me->receive_damage("qi", me->query_skill(bskill, 1),target);
			me->receive_wound("qi", 15 + random(10),target);
			me->receive_wound("jing", 10,target);
			me->apply_condition("snake_poison", random(me->query_skill(bskill, 1)/10) + 1 +
			me->query_condition("snake_poison"));
			me->start_busy(1 + random(2));
		}
	} else {
		msg += CYN"可是$p急忙閃在一旁，躲了開去。\n" NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		傷害對方精氣
		使對手中蛇毒
		若武功不夠，可能反受其害

	出手要求：
		蛤蟆功40
		靈蛇杖法40
		手持蛇杖
		內力400
HELP
	);
	return 1;
}
