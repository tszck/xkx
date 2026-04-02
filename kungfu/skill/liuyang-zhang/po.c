#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#include <xiaoyao.h>

inherit F_SSERVER;
#define PNAME "「" HIR "破神訣" NOR "」"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp, p;
	int lv, cost_neili;
	int mark = 0;
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
		return notify_fail(PNAME "只能空手施展。\n");

	fskill = "bahuang-gong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，難以施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠，難以施展"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(bskill)+"等級不夠，難以施展"+PNAME+"。\n");

	if (userp(me) && (int)me->query("con", 1) < 20)
		return notify_fail("你先天根骨不夠高，難以施展" PNAME "。\n");
		
	if (me->query("max_neili") < 3000)
		return notify_fail("你的內力修爲不足，難以施展" PNAME "。\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("你沒有激發八荒六合唯我獨尊功，難以施展" PNAME "。\n");

	if (me->query("neili") < 800)
		return notify_fail("你現在真氣不足，難以施展" PNAME "。\n");

	msg = HIR "$N" HIR "將八荒六合唯我獨尊功提運至極限，全身真氣迸發，呼的一掌"
              "向$n" HIR "頭頂猛然貫落。\n" NOR;

	ap = me->query_skill("force", 1) + me->query_skill(bskill);
	dp = target->query_skill("force", 1) + target->query_skill("parry");

	if (target->query("shen") * me->query("shen") < 0 ||  userp(target))
		ap += ap / 10;
	if (fam_type(me)=="lingjiu") ap += ap/5;

	if (ap /2 + random(ap) +10 > dp)
	{
		damage = 0;
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
                        msg += HIR "頓時只聽“噗”的一聲，$N" HIR "一掌將$n"
                               HIR "頭骨拍得粉碎，腦漿四濺，當即癱了下去。\n"NOR;
			msg += "( $n" + eff_status_msg(0) + " )\n";

		 target->receive_wound("jing",target->query("eff_jing"),me);
		 target->receive_wound("qi",target->query("eff_qi"),me);
 		 me->add("neili", -100);
		 me->start_busy(1);
	 	 message_combatd(msg, me, target);
		 target->unconcious();
	 	 return 1;
		} else
		{
	 		me->add("neili", -300);
/*			damage = ap *2/3;
			damage += random(damage/2);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage *9/10, me);
			target->receive_damage("jing", damage / 4, me);
			target->receive_wound("jing", damage / 8, me);*/
			damage = ap;
			damage += random(damage);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage / 2, me);
			target->receive_damage("jing", damage / 4, me);
			target->receive_wound("jing", damage / 8, me);
			p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

			msg += HIR "$n" HIR "慌忙抵擋，可已然不及，$N"
                               HIR "掌勁如洪水般湧入體內，接連震斷數根"
                                   "肋骨。\n"NOR;
			msg += "( $n" + eff_status_msg(p) + " )\n";
			
		}
		me->start_busy(3);
	} else
	{
		msg += CYN "$p" CYN "見$P" CYN "掌勁澎湃，決計抵擋不"
                       "住，當即身子向後橫丈許，躲閃開來。\n" NOR;
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
		傷敵精、氣

	出手要求：
		先天根骨20
		八荒六合唯我獨尊功200級
		天山六陽掌手200級
		基本掌法200級
		最大內力3000
		內力800
HELP
	);
	return 1;
}