// nuoyi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "挪移"
int perform(object me, string arg)
{
        string who1, who2;
        object target, victim;
        int damage, lvl, form, skill, i;
        string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/nuoyi") &&
  !me->query("can_perform/qiankun-danuoyi/nuoyi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中沒有這種功能。");
	 
	 if (!me->is_fighting())
   return notify_fail("「乾坤大挪移」只能在戰鬥中使用。\n");
        if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你的內力修為不足以使用乾坤挪移大法。\n");
        if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("你現在內力太弱，不能使用乾坤挪移大法。\n");


	fskill = "jiuyang-shengong";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"未到火候，無法施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"修為不夠，小心走火入魔！\n");

	if( !arg )
	{
		target = offensive_target(me);
  	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
			return notify_fail("乾坤大挪移大法只能對戰鬥中的對手使用。\n");
		form = 1;
	}
	
	else
	{
		target = offensive_target(me);
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
			return notify_fail("乾坤大挪移只對戰鬥中對手使用。\n");
		victim = present(arg, environment(me));
		if( !victim || !victim->is_character() || victim==me) 
			return notify_fail("你想挪移攻擊的對象不在這裏。\n");
	   if((victim->name())=="公平子")
	    	return notify_fail("你不可以對公平子使用乾坤大挪移。\n");
  	notify_fail("你不能攻擊這個人。\n");
		if (!userp(victim) && !victim->accept_hit(me)) return 0;
		form = 2;
	}

	skill = (int)me->query_skill("dodge", 1);
	lvl = random((int)(skill/30));

	if( form == 1 ) /* 反擊對手 */
	{
		msg = CYN "$N默運神功，使出乾坤大挪移大法。\n"NOR;
		me->start_busy(3);
		if(random(me->query("neili")) > target->query("neili")/3 )
		{
			target->start_busy(random(3));
			damage = skill/2 + lvl*target->query("jiali",1);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/3,me);
			me->add("neili", -damage);
			msg += CYN "將$n"CYN"的內力全數反擊回去！\n" NOR;
			if( damage < 20 )
				msg += HIY "結果$n"HIY"受到$N"HIY"的內力反震，悶哼一聲。\n"NOR;
			else if( damage < 40 )
				msg += HIY "結果$n"HIY"被$N"HIY"以內力反震，「嘿」地一聲退了兩步。\n"NOR;
			else if( damage < 80 )
				msg += RED "結果$n"RED"被$N"RED"以內力一震，胸口有如受到一記重錘，連退了五六步！\n"NOR;
			else
				msg += HIR "結果$n"HIR"被$N"HIR"的內力一震，眼前一黑，象一捆稻草一樣飛出去好幾丈遠！\n"NOR;
		}
		else 
		{
			msg += CYN"可是$n"CYN"內力深厚，絲毫不為所動。\n"NOR;
			me->add("neili", -100);
		}
		message_combatd(msg, me, target);
		return 1;
	}
	else
	{
		write( CYN "你默運神功，使出乾坤大挪移大法，試圖將" + target->name() + CYN+"的攻擊挪移到" + victim->name() + CYN+"身上。\n"NOR);
		tell_object(victim, CYN"忽然，你發現有一股奇怪的力量向你襲來！\n"NOR);
		me->start_busy(3);
		if(random(me->query("neili")) > target->query("neili")/2)
		{
			write( CYN"哈哈，成功了！\n"NOR);
			if( target == victim)
			{
				tell_object(target, CYN"你身不由己，一招擊向自己！\n"NOR);
				message("combatd",CYN+target->name()+"忽然如中魔一般，招招擊向自己！\n\n"NOR, environment(me), target);
				for(i = 0; i < lvl; i++)
					COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
			}
			else
			{
				tell_object(target, CYN"你身不由幾，向" + victim->name() + CYN+"撲去！\n"NOR);
				message("vision", CYN"\n" + target->name() + CYN+"忽然向" + victim->name() +CYN+"撲去！\n\n"NOR, environment(me), ({target, victim}) );
					tell_object(victim, CYN"\n" + target->name() + "忽然向你撲來！\n\n"NOR);
				COMBAT_D->do_attack(target,victim,target->query_temp("weapon"));
				if(random(me->query("combat_exp")) >
					(int)victim->query("combat_exp")/2 )
				{
					target->delete("env/combatd");
					victim->delete("env/combatd");
					if(!victim->is_killing(target))
						victim->kill_ob(target);
				}
				else
				{
					tell_object(victim, CYN"你一定神，原來是" + me->name() + CYN+"在搗鬼！\n"NOR);
					tell_object(target, CYN"還好，幸虧"+victim->name()+CYN+"經驗老到，沒有上當。\n"NOR);
					write( CYN "不好，被" + victim->name() + CYN+"發覺了！\n"NOR);
					if(!victim->is_killing(me))
						victim->kill_ob(me);
				}
				target->start_busy(random(3));
				me->add("neili", -300);
			}
		}
		else
		{
			write( CYN"可惜沒成功。\n"NOR);
			tell_object(target, CYN"你強用心神，終於控制住自己。\n"NOR);
			me->add("neili", -100);
		}
		return 1;
	}
}

int help(object me)
{
	write(WHT"\n乾坤大挪移之挪移"NOR"\n");
	write(@HELP

	使用功效：
		nuoyi :  用來反擊敵手的攻擊。
		nuoyi <他人> :  用來將當前出手人物的攻擊挪移到他人身上。
				可以把敵手的攻擊挪移給他自身。
	出手要求：
		九陽神功50級
		乾坤大挪移50級
		內力修為1500
		內力1000
HELP
	);
	return 1;
}

