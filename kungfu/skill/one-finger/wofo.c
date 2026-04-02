// wofo.c 一指禪 「皈依我佛」
// Last Modified by winder on Mar. 30 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "皈依我佛"
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
		return notify_fail("牽制攻擊只能對戰鬥中的對手使用。\n");

	//兵器空手均可
	
	fskill = "zhanzhuang-gong";
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
		return notify_fail("你的"+to_chinese(fskill)+"的火候不能出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"修爲不夠，使不出"+PNAME+"。\n");

	if((int)me->query_str() < 30)
		return notify_fail("你膂力不夠，不能使用這一絕技！\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你內力現在不夠, 不能使用皈依我佛！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧！\n");

	msg = HIY"$N"HIY"使出一指禪絕技「皈依我佛」，罩住了$n"HIY"的全身要穴, 使$n"HIY"動彈不得。\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P一指正中$p的檀中大穴，$p微微一笑，行動竟絲毫不受阻礙，$P一驚之下，呆在當場。\n"NOR;
			me->start_busy(4);
			me->add("neili", -300);
		} else {
			msg += "結果$p被$P點了個動彈不得！\n" NOR;
			target->start_busy( (int)me->query_skill(bskill,1) / 20);
			me->add("neili", -400);
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
		使敵人長時間不能移動或反擊，但不成功的話自己就會暴露
		在對方的猛烈攻擊之下。

	出手要求：
		站樁功100級
		基本指法150級
		一指禪150級
		內力800
		後天膂力30
HELP
	);
	return 1;
}

