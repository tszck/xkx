//duan.c 奪命三斧之「斷雲斬」
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>
#define PNAME "「斷雲斬」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
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
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "axe")
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
	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"還使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(sskill)+"功力還使不出"+PNAME+"。\n");
	if( (int)me->query("neili") < 400 )
		return notify_fail("你的內力不夠。\n");
	me->add("neili", -200);
msg = HIC"$N突然暴喝一聲，將手中巨斧斜向上舉起，然後在半空中劃出一
道圓弧，隨即徑直斜下斬向$n！這一瞬間，$n只覺得呼吸都停止了！\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (!target->is_busy())
		target->start_busy( (int)me->query_skill(bskill) / 30);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
                me->start_busy(1);
		msg += RED "只見$n被$N一斧砍中，胸前裂開一道深深的傷口，血如箭般噴射而出！\n"NOR;
	} else {
		msg += HIC "可是$p急忙抽身躲開，$P這招沒有得逞。\n" NOR;
	        me->start_busy(1+random(2));
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
		枯榮禪功70級
		斷雲斧70級
		內力400
HELP
	);
	return 1;
}

