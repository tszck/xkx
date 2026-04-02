// tiaoyan.c 奪命三斧之「挑眼式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「挑眼式」"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不對。\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"還使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"功力還使不出"+PNAME+"。\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的內力不夠。\n");
	if( target->query_temp("block_msg/all") )
		return notify_fail(target->name()+ "正象只無頭蒼蠅，快放膽攻擊吧。\n");
	msg = HIG "$N使出奪命三斧之「挑眼式」，斧尖疾挑$n雙眼。\n";

	me->start_busy(1);
	me->add("neili", -200);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		msg += "結果$p只覺得眼前一黑，雙眼一陣劇痛，接着什麼也看不見了。\n" NOR;
		damage = (int)me->query_skill(bskill, 1)/5;
		if (!target->is_busy())
		target->start_busy((int)me->query_skill(bskill, 1) / 30 + 3);
		target->receive_wound("qi", damage,me);
	  message_combatd(msg, me, target);
	  target->set_temp("block_msg/all",1);
	} else {
		msg += "可是$p看破了$P的企圖，並急忙躲開了。\n" NOR;
	message_combatd(msg, me, target);
	}
//	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血
		使對方失去視覺直至下次登錄

	出手要求：
		枯榮禪功150級
		斷雲斧150級
		內力600
HELP
	);
	return 1;
}

