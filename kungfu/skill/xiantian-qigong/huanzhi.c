// huanzhi.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/huanzhi") &&
  !me->query("can_perform/xiantian-qigong/huanzhi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");
	if( me->is_fighting() ) return notify_fail("戰鬥中煉丹？找死嗎？\n");

	if(me->query("class") != "quanzhen")
		return notify_fail("你不是玄門清修之士，無法煉製丹藥！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(me->query_condition("quanzhen_drug")>0)
		return notify_fail("你剛接觸丹藥不久，不宜再煉。\n");
	if((int)me->query_skill("xiantian-qigong", 1) < 60)
		return notify_fail("你的先天氣功修為還不夠。\n");
	if((int)me->query("neili") < 200) 
		return notify_fail("你的真氣不夠。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("你受傷過重，只怕一運真氣便有生命危險！\n");

	write( HIW "你坐下來開始運功煉製丹藥。\n" NOR);
	message("vision",
		HIW + me->name() + "運起先天氣功開始煉製丹藥。\n" NOR,
		environment(me), me);
	me->add("neili", -150);
	me->set("jiali", 0);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"mess",me :),5);
	me->apply_condition("quanzhen_drug", 10);
	return 1;
}
void mess(object me)
{
	object ob;
	if (random(10) > 7)
	{
		seteuid(getuid());
		ob=new("/clone/medicine/nostrum/huanzhidan");
message_vision("$N盤膝而坐，兩掌合十，漸漸的掌縫中露出一線金黃的光芒，有一粒
"+HIY"三清換質丹"NOR+"啪的一聲，掉在膝上。\n",me);
		ob->move(me);
	}
	else
	{
message_vision("$N盤膝而坐，兩掌合十，漸漸的頭上滲出一粒粒豆大的冷汗，慢慢地
委頓在地。好累啊！\n",me);
	}
	return;
}

int help(object me)
{
	write(WHT"\n先天氣功之換質"NOR"\n");
	write(@HELP

	使用功效：
		煉製三清換質丹

	出手要求：
		先天氣功60級
		內力200
		身為全真門下道士
HELP
	);
	return 1;
}

