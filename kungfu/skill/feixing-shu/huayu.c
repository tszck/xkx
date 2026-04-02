// huayu.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "滿天花雨"

int perform(object me, object target)
{
	int skill, i;
	string msg;
	object weapon, *ob;
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
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不對。\n");

	fskill = "huagong-dafa";
	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("你內力不夠了。\n");
	skill = me->query_skill(bskill, 1);
	
	target->receive_damage("qi", (int)skill/ 3,me);

	msg= HIY"只聽一股勁風從$N"HIY"的右側發出，$N"HIY"手中的"+weapon->name()+"如煙雨般向$n"HIY"籠罩過去！\n"NOR;
	
	if(random(skill)>target->query_skill("parry")/2)
	{
		msg += "結果$p被$P攻了個措手不及！\n" NOR;
		target->receive_wound("qi", skill+random(skill),me);
		target->start_busy(1+random(2));
		me->start_busy(1);
		me->add("neili", -200);
	} else {
		msg += "可是$p躲過了$P的最後一擊。\n" NOR;
		me->start_busy(2);
		me->add("neili", -250);
	}
	message_combatd(msg, me, target);
	ob = all_inventory(me);	 //use out all throwing
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( (string)ob[i]->query("equipped")!="wielded" ) continue;
		ob[i]->unequip();
		ob[i]->move(environment(me));
	}
	me->reset_action();
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
		化功大法100級
		飛星術100級
		內力300
HELP
	);
	return 1;
}

