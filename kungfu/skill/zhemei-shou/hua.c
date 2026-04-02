#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";


inherit F_SSERVER;
#define PNAME "「" HIR "化妖功" NOR "」"
#include <xiaoyao.h>
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

	fskill = "beiming-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 250 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不夠，難以施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠，難以施展"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(bskill)+"等級不夠，難以施展"+PNAME+"。\n");

	if (userp(me) && (int)me->query("dex", 1) < 20)
		return notify_fail("你先天身法不夠靈活，難以施展" PNAME "。\n");
		
	if (me->query("max_neili") < 4000)
		return notify_fail("你的內力修爲不足，難以施展" PNAME "。\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("你沒有激發北冥神功，難以施展" PNAME "。\n");

	if (me->query("neili") < 800)
		return notify_fail("你現在真氣不足，難以施展" PNAME "。\n");

    msg = HIM "$N" HIM "深深吸進一口氣，單手揮出，掌緣頓時霞光萬道，漾出"
	      "七色虹彩向$n" HIM "席捲而至。\n" NOR;

	ap = me->query_skill("dodge", 1) + me->query_skill(bskill);
	dp = target->query_skill("dodge", 1) + target->query_skill("parry");

	if (target->query("shen") * me->query("shen") < 0 ||  userp(target))
		ap += ap / 10;

	if (ap * 2 / 3 + random(ap) +10 > dp)
	{
		damage = 0;
		lv = me->query_skill(sskill, 1);
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
			msg += HIM "只聽$n" HIM "一聲尖嘯，$N" HIM "的七色掌"
			       "勁已盡數注入$p" HIM "體內，頓時將$p" HIM "化"
			       "爲一灘血水。\n" NOR ;
			msg += "( $n" + eff_status_msg(0) + " )\n";

		 target->receive_wound("jing",target->query("eff_jing"),me);
		 target->receive_wound("qi",target->query("eff_qi"),me);
		 me->start_busy(1);
		 me->add("neili",-100);
		 message_combatd(msg, me, target);
		 target->unconcious();
		 return 1;
		} else
		{
			damage = ap;
			damage += random(damage);

			target->receive_damage("qi", damage, me);
			if (fam_type(me)=="xiaoyao")
			{
				target->receive_wound("qi", damage / 2, me);
				target->receive_damage("jing", damage / 4, me);
				target->receive_wound("jing", damage / 8, me);
			}
			me->add("neili",-1 * (damage /3+50));
			p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

			msg += HIM "$n" HIM "只是微微一愣，$N" HIM "的七色掌勁已破體而"
			       "入，$p" HIM "便猶如身置洪爐一般，連嘔數口鮮血。\n" NOR;
			msg += "( $n" + eff_status_msg(p) + " )\n";
			
			me->start_busy(3);
		}
	} else
	{
		msg += CYN "$p" CYN "見狀大驚失色，完全勘破不透$P"
		       CYN "招中奧祕，當即飛身躍起丈許，躲閃開來。\n" NOR;
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
		先天身法20
		北冥神功250級
		天山折梅手200級
		基本手法200級
		最大內力4000
		內力800
HELP
	);
	return 1;
}