// baodan.c 豹子膽
// Last Modified by winder on Aug. 1 2002

#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void init();

void create()
{
	set_name("豹子膽", ({ "baozi dan", "dan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顆");
		set("long", CYN"這是一顆象拳頭一樣大的豹子膽，又黑又綠。\n"NOR);
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	me->add("food", 50);

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("max_jingli", -1);
		me->add("eff_jingli", -1);
		me->set("jingli", 0);
		me->apply_condition("bonze_drug", 30);
		message_vision(HIR "$N喫下一顆豹子膽，只覺得肝腸寸斷，五臟欲裂，原來服食太多藥物，藥效適得其反！\n" NOR, this_player());
		destruct(this_object());
		return 1;
	}

	if( !me->query_temp("qz/baozidan") )
	{
		me->add_temp("apply/attack", 100);
		me->set_temp("qz/baozidan", 1);
		if(random(2)) me->set("max_jingli",me->query("max_jingli",1)+2);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query("con")*10);
	}

	me->add("neili", 500);
	me->apply_condition("bonze_drug",
	me->query_condition("bonze_drug")+30);
	message_vision(HIY "$N吞下一顆豹子膽，只覺得全身充滿熱氣，鬥志昂揚，混身有勁。\n" NOR, me);
	destruct(this_object());
	return 1;
}

void remove_effect(object me)
{
	me->add_temp("apply/attack", -100);
	me->delete_temp("qz/baozidan");
	tell_object(me, "過了一會兒，豹子膽帶來的餘勁好象消失了。\n");
}

