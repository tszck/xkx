// jingsuck.c
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/jingsuck") &&
  !me->query("can_perform/huagong-dafa/jingsuck") && 
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
		return notify_fail("你要吸取誰的精氣？\n");

	notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if (target->query("race") != "人類")
		return notify_fail("搞錯了！只有人才能有精氣！\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你剛剛吸取過精氣！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必須空手才能施用化功大法吸人精氣！\n");

//	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 45 )
		return notify_fail("你的化功大法功力不夠，不能吸取對方的精氣。\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("你的內力不夠，不能使用化功大法。\n");

	if( (int)target->query("jing") < 45 )
		return notify_fail( target->name() +
			"已經精氣渙散，你已經無法從他體內吸取精氣了！\n");

	message_combatd(
		HIR "$N突然神祕的一笑，雙掌一前一後對準$n的太陽穴拍了過來！\n\n" NOR, me, target );

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
		tell_object(target, HIR"你猛覺額角兩側如針刺般劇痛，神志迷困，頭腦中一片空白！\n" NOR);
		tell_object(me, HIG"你覺得" + target->name() + "的精氣自手掌源源不絕地流了進來。\n" NOR);

		target->receive_damage("jing", (int)me->query_skill("huagong-dafa", 1) );
		me->add("jing", (int)me->query_skill("huagong-dafa", 1) );
		me->add("eff_jing", (int)(me->query_skill("huagong-dafa", 1)*2/3) );
		if ( me->query("eff_jing") > me->query("max_jing") ) me->set("eff_jing", me->query("max_jing"));

		if( target->query("combat_exp") >= me->query("combat_exp") )
		{
//			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("combat_exp", 1);
		}

		me->start_busy(3);
		target->start_busy(random(3));
		me->add("neili", -5);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_combatd(HIY"可是$p看破了$P的企圖，內力猛地一震，借勢溜了開去。\n" NOR, me, target);
		me->start_busy(3);
		call_out("del_sucked", 4, me);
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
	write(WHT"\n化功大法之吸取精氣："NOR"\n");
	write(@HELP

	使用功效：
		吸取對方精氣
		增強自己精氣

	出手要求：
		化功大法45級
		內力10
HELP
	);
	return 1;
}

