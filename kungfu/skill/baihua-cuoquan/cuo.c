// cuo.c 百花錯拳 錯字訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「錯」字訣"

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
  string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		return notify_fail("你必須空手才能使用"PNAME"！\n");
		
	fskill = "honghua-shengong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"的修爲不夠。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"的修爲不夠，不能用"+PNAME+"。\n");
	if( (int)me->query("neili") < 800 )
		return notify_fail("你的內力不夠！\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的內力修爲還不夠！\n");

	msg = HIY"$N"HIY"使出百花錯拳的錯字訣，出手似是而非，讓對手不知你的真實虛實，\n" NOR;
	if((int)random(me->query("combat_exp")) >	(int)target->query("combat_exp") / 3)
	{
  	me->add("neili", -400);
		me->set_temp("kongming", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 1, 0:), 10);
		msg += HIY"$n"HIY"的招數明顯被$N攪亂，招招擊在空處！\n"NOR;
// 功效在combatd.c中體現，同空明拳的絕招。但時間控制在2秒即兩招。
	}
	else{
	  me->add("neili", -100);
		msg += HIG"但$n"HIG"早對百花錯拳瞭如在心，不受$N"HIG"拳法虛實影響！\n"NOR;
	  me->start_busy(2);
	}
	message_combatd(msg, me, target);
	return 1;
}

void remove_effect(object me, int i, int j)
{
	if ( (int)me->query_temp("kongming") ) 
	{
		me->delete_temp("kongming");
		tell_object(me, HIR"你的內力一頓，錯字訣收功了。\n"NOR);
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		以虛騙實，以柔克制對手猛招

	出手要求：
		紅花神功150級
		百花錯拳150級
		內力修爲1000
		內力800
HELP
	);
	return 1;
}

