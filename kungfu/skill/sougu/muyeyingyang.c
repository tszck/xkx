// muyeyingyang.c 牧野鷹揚
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "牧野鷹揚"
int perform(object me, object target)
{
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
		
	if( me->query_temp("weapon"))
		return notify_fail("你只能空手才能施展牧野鷹揚！\n");

	if((int)me->query_str() < 30)
		return notify_fail("你臂力不夠，不能使用牧野鷹揚！\n");

	fskill = "jiuyang-shengong";
	bskill = "claw";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，目前還不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修爲不夠，目前還不能使用"+PNAME+"。\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你內力現在不夠，不能使用牧野鷹揚！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧！\n");

	msg = HIY "$N"HIY"使出搜骨鷹爪功絕技「牧野鷹揚」，雙爪驀地抓向$n"HIY"的全身要穴。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
	  		msg += HIY "$p不思避閃，反而搶身迎上，任$P拿住自身要穴，行動卻絲毫不爲之受阻。\n"NOR;
			me->start_busy(random(4) + 1);
			me->add("neili", -100);
		} else {
			msg += HIG "結果$p被$P點中要穴，立時動彈不得! \n" NOR;
			target->start_busy((int)me->query_skill(bskill,1)/25+2);
			me->add("neili", -100);
		}
	} else {
		msg += HIG "可是$p看破了$P的企圖，並沒有上當。\n" NOR;
		me->start_busy(4);
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
		遲滯對方出手

	出手要求：
		九陽神功100級
		搜骨鷹爪功150級
		內力800
		後天膂力30
HELP
	);
	return 1;
}

