// maxsuck.c
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/maxsuck") &&
  !me->query("can_perform/huagong-dafa/maxsuck") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if ( target == me ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("在這裏不能攻擊他人。\n");

	if( !objectp(target) ||
		target->query("id") == "gongping zi" ||
		target->query("id") == "zhang men" ||
		target->query("id") == "mu ren" ||
		target->query("id") == "shi ren" ||
		target->query("id") == "jiguan ren" ||
		target->query("id") == "xiangpi ren" ||
		target->query("id") == "jin ren" ||
		target->query("id") == "du jiangshi")
		return notify_fail("你要吸取誰的丹元？\n");

	notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;


	if (target->query("race") != "人類")
		return notify_fail("搞錯了！只有人才能有丹元！\n");

	my_max = me->query("max_neili");
	tg_max = target->query("max_neili");

	if ( me->query_temp("sucked") )
		return notify_fail("你剛剛吸取過丹元！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能施用化功大法吸人丹元！\n");

//	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 90 )
		return notify_fail("你的化功大法功力不夠，不能吸取對方的丹元！\n");

	if( (int)me->query("neili") < 20 )
		return notify_fail("你的內力不夠，不能使用化功大法。\n");

	if( (int)me->query("neili") > 2*(int)me->query("max_neili")  )
		return notify_fail(HIR"你只覺全身真氣亂闖，看來要調理內息了。\n"NOR);

	if( (int)me->query_skill("force") < (int)me->query("max_neili") /10 )
		return notify_fail("你的內功太低了，再吸取也是徒勞。\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() +
			"丹元渙散，功力未聚，你無法從他體內吸取任何東西！\n");

	if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
		return notify_fail( target->name() +
			"的內功修為遠不如你，你無法從他體內吸取丹元！\n");

	message_combatd( HIR "$N全身骨節爆響，雙臂暴長數尺，掌緣猛地向$n的天靈拍了下去！\n\n" NOR, me, target );

        if ( living(target) && !target->query_temp("noliving") )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
	dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIR "你只覺天頂骨裂，全身功力貫腦而出，如融雪般消失得無影無蹤！\n" NOR);
		tell_object(me, HIG "你覺得" + target->name() + "的丹元自手掌源源不絕地流了進來。\n" NOR);

		target->add("max_neili",  -1*(1+(me->query_skill("huagong-dafa", 1)-90)/5) );
		me->add("max_neili",       1*(1+(me->query_skill("huagong-dafa", 1)-90)/5) );
		if ( target->query("max_neili") <1) target->set("max_neili",0);

//		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
			me->add("potential",  3);
		me->add("combat_exp", 10);

		me->start_busy(7);
		target->start_busy(random(7));
		me->add("neili", -10);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_combatd(HIY "可是$p看破了$P的企圖，內力猛地一震，借勢溜了開去。\n" NOR, me, target);
		me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

int help(object me)
{
	write(WHT"\n化功大法之吸取丹元："NOR"\n");
	write(@HELP

	使用功效：
		吸取對方丹元
		增強自己內力上限

	出手要求：
		化功大法90級
		內力20
HELP
	);
	return 1;
}

