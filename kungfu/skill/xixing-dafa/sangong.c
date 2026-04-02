// sangong.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
//  if ( userp(me) && !wizardp(me) && 
//  !me->query("perform/sangong") &&
//  !me->query("can_perform/xixing-dafa/sangong") && 
//  !me->query_temp("murong/xingyi"))
//   return notify_fail("你所使用的內功中沒有這種功能。");
	if( me->is_fighting() ) return notify_fail("戰鬥中散功？找死嗎？\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if((int)me->query_skill("xixing-dafa", 1) > 20)
		return notify_fail("你現在不必散功。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("你受傷過重，只怕一運真氣便有生命危險！\n");

	message_vision( HIY"$N坐下來開始散功：“當令丹田常如空箱，恆似深谷，空箱可貯物，深谷可容水。若有內息，散之於任脈諸穴。”\n" NOR, me);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"sangong",me :),5);
	return 1;
}
void sangong(object me)
{
	object ob;
	message_vision(HIG"$N頓時覺得丹田有氣，散之任脈，如竹中空，似谷恆虛……\n"NOR,me);
	me->set("max_neili", 0);
	me->set("neili", 0);
	return;
}

int help(object me)
{
	write(WHT"\n吸星大法之散功"NOR"\n");
	write(@HELP

	使用功效：
		練習吸星大法必須經過散功，散去全身內力

	出手要求：
		吸星大法小於10級
HELP
	);
	return 1;
}

