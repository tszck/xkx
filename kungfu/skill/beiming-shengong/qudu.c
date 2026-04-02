// qudu.c
// Last Modified by sir on 5.4.2002

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/qudu") &&
  !me->query("can_perform/beiming-shengong/qudu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( (!target))
		return notify_fail("你要用真氣為誰驅毒？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("戰鬥中無法運功驅毒！\n");

	if( me->is_busy() )
		return notify_fail("你現在正忙着呢，哪有空運功？\n");

	notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( target->is_busy())
		return notify_fail(target->name()+"現在正忙着呢！\n");

	if( !target->query_condition("ss_poison"))
		return notify_fail(target->name()+"並沒有中生死符！\n");
		
	if( (int)me->query_skill("beiming-shengong",1) < 50 )
		return notify_fail("你的北冥神功修為不夠。\n");

	if( (int)me->query("max_neili") < 150 )
		return notify_fail("你的內力修為不夠。\n");

	if( (int)me->query("neili") < 150)
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query_skill("force") < (int)target->query_skill("force") / 3 )
		return notify_fail( target->name() + "中毒已經深，以你的內功修為恐怕解不了他的生死符！\n");

	if (me != target)
	message_combatd( HIC"$N坐了下來運起北冥神功，將手掌貼在$n背心，緩緩地將真氣輸入$n體內....\n\n過了不久，$N額頭上冒出豆大的汗珠，$n指尖滲出一縷白色霧氣，臉色看起來紅潤多了。\n" NOR, me, target );
    else
    message_vision( HIC"$N右掌以陽剛之氣急拍，左掌以陰柔之力緩運，開始自行化解生死符之毒....\n\n過了許久，$N只覺“陰陵泉”穴上一團窒滯之意霍然而解，關節靈活，説不出的舒適。\n"NOR,me);

//	target->set("qi", (int)target->query("eff_qi"));
	target->clear_condition("ss_poison",0);

	me->add("neili", -100);
	me->start_busy(1);
	if ( userp(target)) target->start_busy(2);

	return 1;
}

int help(object me)
{
	write(WHT"\n北冥神功之驅毒："NOR"\n");
	write(@HELP

	使用功效：
		解生死符

	出手要求：
		北冥神功50級
	        內力150
	        雙方基本內功懸殊不大
HELP
	);
	return 1;
}

