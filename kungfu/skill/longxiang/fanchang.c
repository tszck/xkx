// fanchang.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/fanchang") &&
  !me->query("can_perform/longxinag/fanchang") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( environment(me)->query("no_fight") )
		return notify_fail("這裏不能攻擊別人! \n");
		
	if( !objectp(target) ) target = offensive_target(me);

	if( !target || !target->is_character() || target == me ) 
		return notify_fail("你要對誰使用梵唱？\n");
	notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("你的龍象般若功功力不夠，不能凝神攻擊對方！\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的內力不夠，不能使用龍象般若功。\n");

	message_combatd(HIW "$N面無表情，歌聲如梵唱般貫入$n耳中！\n\n" NOR, me, target );

        if( living(target) && !target->query_temp("noliving") )
		if( !target->is_killing(me) )
			target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("lamaism") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIW"你忽然覺得腦中一片空白，不由自主地隨歌聲舞蹈起來！\n" NOR);
		tell_object(me, HIB"你看到" + target->name() + "隨着你的歌聲手舞足蹈，十分可笑。\n" NOR);

		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)) );
		
		if( target->query("combat_exp") >= me->query("combat_exp") )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -50);

	}
	else
	{	
		message_combatd(HIY "可是$p不爲$P歌聲所動，定力果然不同凡響！\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
int help(object me)
{
	write(WHT"\n龍象般若功之梵唱："NOR"\n");
	write(@HELP

	使用功效：
		損傷對方精氣
		遲滯對方出手

	出手要求：
		龍象般若功50級
		內力50
HELP
	);
	return 1;
}

