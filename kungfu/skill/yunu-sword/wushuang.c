// wushuang.c 玉女劍法 無雙無對
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

//inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
#define PNAME "無雙無對"
int perform(object me, object target)
{
	object weapon;
	int skill;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不對。\n");

	fskill = "zixia-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的內力不夠。\n");

	if( (int)me->query_temp("hsj_wu") ) 
		return notify_fail("你已經在運功中了。\n");

        msg = YEL "$N但覺丹田中一股內力湧將上來，手握" + weapon->name() + HIY"，劍芒暴長，挺劍刺出，運力\n姿式，宛然便是嶽夫人那一招"HIR"
      【 無 雙 無 對 ～～ 寧 氏 一 劍 】"HIY"
藉由此招的精義，你感到一股前所未有的力量正由體內源源而出，一時之間劍勢
如虹，嗤嗤之聲大作，劍刃未到，劍力已將$n全身籠罩住了。\n"NOR;

	message_combatd(msg, me, target);

	skill = (int)me->query_skill(bskill, 1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", -skill/4);
	me->set_temp("hsj_wu", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), skill);
	me->add("neili", -100);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", d_amount);
	me->delete_temp("hsj_wu");
	me->start_busy(4);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增強自己的攻擊力，降低自己的防護力

	出手要求：
		紫霞神功40級
		玉女劍法40級
		內力300
HELP
	);
	return 1;
}

