// pangen.c 鐵掌掌法 「枯樹盤根」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「枯樹盤根」"
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
		
	if( me->query_temp("weapon") )
		return notify_fail("只有空手才能施展「枯樹盤根」。\n");

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

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修為不夠，不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修為不夠，不能使"+PNAME+"。\n");

	if((int)me->query("max_neili") < 500)
		return notify_fail("你內力修為不夠，不能使用枯樹盤根！\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你內力現在不夠，不能使用枯樹盤根！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧！\n");
	msg = HIY"$N使出鐵掌掌法的「枯樹盤根」，左掌猛地向$n的雙手抓去！\n"NOR;
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY"結果$P發現$p兩手殊非血肉之物，被$p一掙就掙脫了。\n"NOR;
			me->start_busy(random(3) + 1);
			me->add("neili", -200);
		} else {
			msg += HIG"結果$p的雙手被$P一把攬住，動彈不得！\n"NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 30) + 2);
			me->add("neili", -300);
		}
	}
	else
	{
		msg += HIY "結果$p兩手急收，$P的出手撲了個空！\n"NOR;
		me->add("neili", -200);
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
		歸元吐納法100級
		鐵掌掌法100級
		內力修為500
		內力300
HELP
	);
	return 1;
}

