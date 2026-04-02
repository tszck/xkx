// you.c 美女拳-古墓幽居
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「古墓幽居」"
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
		return notify_fail("你必須先放下手中的兵器！\n");

	fskill = "yunv-xinfa";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"還未嫺熟，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"級別不夠，不會使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("你現在內力太弱，不能使用古墓幽居。\n");

	msg = HIW"$N"HIW"右手支頤，左袖輕輕揮出，長嘆一聲，使出「古墓幽居」，臉現寂寥之意。\n"NOR;

	if (random(me->query_skill(bskill)) > target->query_skill("force")/3 )
	{
		me->start_busy(random(3));
		damage = (int)me->query_skill("force", 1) + (int)me->query_skill(bskill, 1);
//		damage=damage/2;
		damage = damage/2 + random(damage/2) + random(damage/4);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		target->start_busy(3);
		me->add("neili", -100);

		if( damage < 30 )
			msg += HIY"結果$n"HIY"被$N"HIY"袍袖一拂，悶哼一聲。\n"NOR;
		else if( damage < 55 )
			msg += HIY"結果$n"HIY"被$N"HIY"以袍袖一拂，「騰騰」地退出幾步。\n"NOR;
		else if( damage < 80 )
			msg +=RED"結果$n"HIY"被$N"HIY"以袍袖一拂，胸口有如受到一記重錘，氣血為之一窒！\n"NOR;
		else
			msg +=HIR"結果$n"HIY"被$N"HIY"的袍袖一拂，眼前一黑，渾身氣血翻騰，竟如身入洪爐一般！\n"NOR;
	}
	else
	{
		me->start_busy(3);
		msg += CYN"可是$p看破了$P的企圖，依然穩如泰山，抬手一架格開。\n"NOR;
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
		損傷對方氣血
		遲滯對方出手

	出手要求：
		玉女心法40級
		美女拳50級
		內力150
HELP
	);
	return 1;
}

