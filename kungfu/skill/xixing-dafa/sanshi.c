// sanshi.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
/*  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/sanshi") &&
  !me->query("can_perform/xixing-dafa/sanshi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");*/
	if( me->is_fighting() ) return notify_fail("戰鬥中煉丹？找死嗎？\n");

	if(me->query("family/master_id") != "ren woxing")
		return notify_fail("你不是任教主的弟子，無法煉製丹藥！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if((int)me->query_skill("xixing-dafa", 1) < 100)
		return notify_fail("你的吸星大法修爲還不夠。\n");
	if((int)me->query_skill("kuihua-xinfa", 1) < 100)
		return notify_fail("你的葵花心法修爲太低。\n");
	if((int)me->query("qi") < 300) 
		return notify_fail("你的氣不夠。\n");
	if((int)me->query("neili") < 400) 
		return notify_fail("你的真氣不夠。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("你受傷過重，只怕一運真氣便有生命危險！\n");

	write( HIW "你坐下來開始運功煉製丹藥。\n" NOR);
	message("vision",
		HIW + me->name() + "運起吸星大法開始煉製丹藥。\n" NOR,
		environment(me), me);
	me->add("neili", -300);
	me->add("max_neili", -10);
	me->set("jiali", 0);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"mess",me :),5);
	return 1;
}
void mess(object me)
{
	object ob;
	int now_qi = me->query("eff_qi");
	message_vision("$N盤膝而坐，伸起三指打了個訣，漸漸的頭上滲出一粒粒豆大的冷汗。真累！\n",me);
	me->receive_wound("qi", now_qi - 30);
	me->set("qi", me->query("eff_qi"));
	if (random(10) > 6)
	{
		seteuid(getuid());
		ob=new("/clone/medicine/nostrum/sanshi");
		message_vision("$N煉成三尸腦神丹了。\n",me);
		ob->set("owner", me->query("id"));
		ob->move(me);
	}
	else
		message_vision("$N白折騰了。沒煉成三尸腦神丹了。\n",me);
	return;
}

int help(object me)
{
	write(WHT"\n吸星大法之三尸"NOR"\n");
	write(@HELP

	使用功效：
		煉製三尸腦神丹
		吸星大法煉製的三尸腦神丹，爲天下第一毒藥，中毒者
		的生死，就完全操在煉丹者是否催發的一念間。
		請help cuifa

	出手要求：
		葵花心法100級
		吸星大法100級
		內力400
		氣血300
		身爲任我行的嫡傳弟子
HELP
	);
	return 1;
}

