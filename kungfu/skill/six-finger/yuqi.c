// yuqi.c 馭劍氣
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「馭劍氣」"
int perform(object me,object target)
{
	string msg;
	object weapon, target_w,piece;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
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
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必須空手運功。\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"等級不夠, 不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等級不夠, 不能使"+PNAME+"。\n");

	if( me->query_str() < 30)
		return notify_fail("你的臂力不夠，無法運功！\n");
 
	if( me->query("neili") < 1500 )
		return notify_fail("你的內力不夠，無法運功！\n");
 
	skill = me->query_skill(bskill,1);
	msg = HIY "$N忽然心頭大亂，十指亂伸，內息滾動，直是連綿無盡。霎時
間劍氣縱橫，塵煙四起，\n"NOR;


	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 ) dp = 1;
//	if(userp(me)) me->add("neili", -800);
	if( random(ap) > dp )
	{
		qi_wound = (int)me->query_skill(bskill,1) * 2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(3));
		me->add("neili", -1000);

		msg += HIR"$n頓時手足無錯，全身刺痛錐心，鮮血標出丈多遠！\n"NOR;
		if (objectp(target_w = target->query_temp("weapon")))
		{
			target_w->unequip();
			target->reset_action();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆破碎物事，很象兵器碎片。\n");
      	piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
			msg += HIY "同時只聽到「叮噹」一聲兵刃破碎的聲音，$n頓覺手中一震，兵器竟被劍氣誤打誤撞，脫手而出！\n" NOR;
		}
	}
	else
	{
		msg += HIG "只見$n不慌不忙，輕輕一閃，躲過了$N的氣劍！\n"NOR;
		me->start_busy(4);
		me->add("neili", -500);
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
		損傷對方氣血
		損毀對方兵刃

	出手要求：
		枯榮禪功150級
		六脈神劍120級
		內力1500
		後天膂力30
HELP
	);
	return 1;
}

