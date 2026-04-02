// xuanfeng.c 鐵掌掌法 「旋風快掌」

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「旋風快掌」"
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
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
		
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("使「旋風快掌」時不能拿着兵器！\n");

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

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"修爲不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"還不到家，無法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的真氣不夠！\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的內力修爲不夠！\n");

	msg = HIY "$N"HIY"使出鐵掌的絕技「旋風快掌」，出手陡然加快！\n" NOR;
	message_combatd(msg, me);

	for (count=0;count<3;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}

	me->add("neili", -300);
	me->start_busy(2);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		連續出手三招

	出手要求：
		歸元吐納法50級
		鐵掌掌法100級
		內力修爲400
		內力300
HELP
	);
	return 1;
}

