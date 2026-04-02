// zhuan.c 打狗棒法「轉」字訣
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「轉」字訣"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
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
		(string)weapon->query("skill_type") != "stick")
		return notify_fail("你使用的武器不對。\n");

	fskill = "huntian-qigong";
	bskill = "stick";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠深厚，不會使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");
	if( (int)me->query("max_neili") < 700 )
		return notify_fail("你的內力修為不夠！\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真氣不夠！\n");
	msg = HIY"$N"HIY"微微一笑，揮"+weapon->name()+"往$n"HIY"臉上橫掃過去，勢挾勁風，甚是峻急。\n";
	me->start_busy(2);
	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2 )
	{
		msg += HIR "$n連忙後仰相避，這麼一來，下盤扎的馬步自然鬆了。$N"+weapon->name()+HIR"迴帶，使個「轉」字訣，往$n腳下掠去，$n立足不穩，撲地跌倒。\n" NOR;
		if(target->query("neili") > 300) target->add("neili", -300 );
		else target->set("neili", 0 );
	} else {
		msg += HIC"可是$n"HIC"後躍一小步，$N"HIC"的"+weapon->name()+HIC"頓時落空。\n" NOR;
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
        消耗敵人的內力

	出手要求：
		混天氣功150級
		打狗棒法150級
		內力修為700
		內力500
HELP
	);
	return 1;
}

