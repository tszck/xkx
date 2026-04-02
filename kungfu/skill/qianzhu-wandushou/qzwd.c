// qianzhu-wandushou.c 千蛛萬毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "千蛛萬毒"
int perform(object me, object target)
{
	string msg;
	int damage, skill;
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
		
		//空手兵器均可
		
	fskill = "wudu-shengong";
	bskill = "hand";
	pskill = "five-poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "shenyuan-gong";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"的功力不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修爲不夠，還不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(pskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(pskill)+"太低，不能使用"+PNAME+"。\n");
//	if( !userp(me))
//		return notify_fail("只有玩家才能玩命。\n");
	if((int)me->query("max_neili") < 700)
		return notify_fail("你內力修爲不夠，不能使用"PNAME"！\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你內力不夠，不能使用"PNAME"！\n");

	if(me->query_temp("qzwd_used"))
		return notify_fail("你剛使用過千蛛萬毒，無法在短時間裏積聚毒力！\n");

	skill = me->query_skill(bskill,1);
	msg = HIR "$N"HIR"一聲獰笑飛身縱起，凌空一指向$n"HIR"的眉心點去。\n";
	message_combatd(msg, me, target);

	if( random(skill) > random((int)target->query_skill("dodge",1)*2/3))
	{
		msg=HIR"只見一縷黑氣從$N"HIR"的指尖透出，只一閃就沒入$n"HIR"的眉心！\n"NOR;
		message_combatd(msg, me, target);
		if(target->query_skill("force", 1) > skill * 12 /10 &&
			random(2)==0)
		{
			msg = RED"$N忽然覺得指力被一團無形的勁力包裹着，緊接着只聽\n$n一聲大喝，$N頓時如一根稻草般被拋向遠處。\n" NOR;
			message_combatd(msg, me, target);
			msg = RED"$P只覺得一股如山的勁力順指尖猛攻過來，只覺得全身毒氣狂竄。\n忽然胸口一痛，不由“哇”的一聲吐出一口黑血！\n" NOR;
			message_combatd(msg, me);
			damage = skill +(int)me->query_skill("force",1);
			if(damage < 50 ) damage = 50;
			me->receive_wound("qi", damage,target);
			me->add("neili", -100);
			me->start_busy(2);
		}
		else{
			msg = HIR"$n"HIR"不由一聲慘嚎摔倒在地，身體已痛苦得蜷縮成一團！\n" NOR;
			message_combatd(msg, me, target);
			damage= skill + (int)me->query_skill("force", 1)/2;
			if(damage > 900 ) damage = 900;
			target->receive_wound( "qi",damage,me);
			if( me->query_skill(pskill, 1) > 100)
			{
				target->apply_condition("snake_poison", (int)target->query_condition("snake_poison") + 50 );
				target->apply_condition("wugong_poison", (int)target->query_condition("wugong_poison") + 50 );
				target->apply_condition("zhizhu_poison", (int)target->query_condition("zhizhu_poison") + 50 );
				target->apply_condition("xiezi_poison", (int)target->query_condition("xiezi_poison") + 50 );
				target->apply_condition("chanchu_poison", (int)target->query_condition("chanchu_poison") + 50 );
			}
			me->add("neili", -300);
			target->start_busy(4);
		}
	}
	else {
		msg = HIG "可是$n早有準備，一個懶驢打滾，堪堪躲過了這一招。\n" NOR;
		me->start_busy(4);
		message_combatd(msg, me, target);
		me->add("neili", -100);
	}
	if( !target->is_killing(me) ) target->kill_ob(me);
	me->set_temp("qzwd_used",1);
	call_out ("qzwd_used", 6,me);
	return 1;
}
void qzwd_used(object me)
{
	me->delete_temp("qzwd_used");
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方氣血
		使對手身中五毒（蛇、蠍子、蜈蚣、蟾蜍、蜘蛛）

	出手要求：
		五毒神功80級
		五毒毒技100級
		千蛛萬毒手100級
		內力修爲700
		內力500
HELP
	);
	return 1;
}

