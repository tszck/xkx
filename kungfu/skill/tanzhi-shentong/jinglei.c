// jinglei.c 彈指驚雷
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「彈指驚雷」"
int perform(object me,object target)
{
	string msg;
	object weapon2 ;
	int skill, dp, wound;
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

	if( me->query_temp("weapon"))
		return notify_fail("你使用了武器。\n");

	fskill = "bibo-shengong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"未到火候, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的內力不夠，無法運用「彈指驚雷」！\n");
 
	skill = me->query_skill(bskill, 1);
	msg = HIC "$N"HIC"使出彈指神通之「彈指驚雷」, 頓時眼內精光暴射，\n" NOR;
	message_combatd(msg, me, target);
 
	dp = target->query("combat_exp")/4;
	if( dp < 1 ) dp = 1;
	if( random(me->query("combat_exp")) > dp)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIM "$n微微一笑，搶身而上，全然不顧$N的攻勢，$N一指點在$n的氣海穴上，$n似乎毫無知覺，反而痛下殺手，連連出招。\n"NOR;
			me->start_busy(random(5) + 1);
			me->add("neili", -150);
		} else {
			if(userp(me)) me->add("neili",-150);
			msg =HIC"$n"HIC"只覺得眼前一花，氣海穴上微微一痛，全身真氣狂泄而出！\n"NOR ;
			if ( objectp(weapon2 = target->query_temp("weapon")))
			{
				msg += HIC"同時手腕一麻，手中";
				msg += weapon2->name();
				msg += HIC"脫手而出！\n" NOR;
				weapon2->move(environment(me));
			}
			wound = skill + random(400);
			if((int)target->query("neili") < wound)
				wound = target->query("neili");
			target->add("neili", -wound);
			target->receive_damage("jing", wound/2 + random(100),me);
			target->receive_wound("jing", wound/2,me);
			if (!target->is_busy())
			target->start_busy(5);
			me->start_busy(2);
		}
	}
	else
	{
		msg ="可是$n的看破了$N的企圖，立刻採取守勢，使$P的「彈指驚雷」沒有起到作用。\n"NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血
		減損對方內力
		擊落對方兵刃

	出手要求：
		碧波神功100級
		彈指神通120級
		內力150
HELP
	);
	return 1;
}

