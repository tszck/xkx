// lingbo.c 洛神凌波
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h>
inherit F_SSERVER;
#define PNAME "洛神凌波"
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
	return notify_fail("你一個人跳甚麼？\n");

	if( me->query("gender") == "無性")
		return notify_fail(HIY "一個公公，滿場亂跳，羞也不羞？\n" NOR);
	
	//空手兵器均可

	fskill = "beiming-shengong";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail(HIY"你的"+to_chinese(fskill)+"修為不夠。\n"NOR);

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail(HIY"你的"+to_chinese(sskill)+"不夠熟練。\n"NOR);

	if((int)me->query("neili") < 400)
		return notify_fail(HIY "你現在真氣不足。\n" NOR);

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顧不暇，放膽攻擊吧！\n");

	if( me->query("gender") == "男性")
	       {msg = HIC 
"$N提起真氣，依照先天伏羲六十四卦，不理$n如何出招，自顧自的將
凌波微步由頭到尾迅速無比的走了一次。只見$N意態飄逸，影子亂飛，
$n卻是一點皮毛也沾不上。$N真個將逍遙二字發揮得淋漓盡至。\n" NOR;}
	else   {msg = HIG 
"$N提起真氣，依照先天伏羲六十四卦，不理$n如何出招，自顧自的將
凌波微步由頭到尾迅速無比的走了一次。$N仿如洛神再生，微步凌波，
$n卻是一點皮毛也沾不上。$N真個將逍遙二字發揮得淋漓盡至。\n" NOR;}

	if(
	(fam_type(me)=="xiaoyao" &&
	random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/4) ||
	(fam_type(me)!="xiaoyao" &&
	random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/3))
	{
		msg += HIW "結果$p被$P圍着轉得頭暈眼花！\n" NOR;
		target->start_busy( (int)me->query_skill(bskill, 1) / 30);
		me->add("neili", -100);
		me->start_busy(1);
	} else {
		msg += HIG "$p只是勉強的逃了開去。\n" NOR;
		me->add("neili", -100);
		me->start_busy(2);
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
		北冥神功100級
		凌波微步100級
		內力400
		不能做太監
HELP
	);
	return 1;
}

