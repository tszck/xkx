// zhen.c 太極拳「震」字訣
// Last Modified by suncity on JUN. 5 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「震」字訣"
int perform(object me, object target)
{
	int damage;
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
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能使用「震」字訣！\n");

	fskill = "taiji-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 30 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠高，不能用來反震傷敵。\n");

	if( (int)me->query_skill(sskill, 1) < 30 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你現在內力太弱，不能使用「震」字訣。\n");

	msg = CYN "$N"CYN"默運神功，使出太極拳「震」字訣，企圖以內力震傷$n。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/4 )
	{
		me->start_busy(3);
		target->start_busy(random(3));

		damage = (int)me->query_skill("force", 1);
		damage = damage + (int)me->query_skill(bskill,1);
		
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -damage/5);

		if( damage < 60 )
			msg += HIY"結果$n受到$N的內力反震，悶哼一聲。\n"NOR;

		else
			if( damage < 80 )msg += HIY"結果$n被$N以內力反震，「嘿」地一聲退了兩步。\n"NOR;
			else if( damage < 160 ) msg += RED"結果$n被$N以內力一震，胸口有如受到一記重錘，連退了五六步！\n"NOR;
				else msg += HIR"結果$n被$N的內力一震，眼前一黑，身子向後飛出丈許！！\n"NOR;

	} else
	{
		me->start_busy(1);
		msg += CYN"可是$p看破了$P的企圖，並沒有上當。\n"NOR;
                me->add("neili", -50);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血

	出手要求：
		太極神功30級
		太極拳30級
		內力100
HELP
	);
	return 1;
}

