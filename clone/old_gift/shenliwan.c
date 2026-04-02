// Last Modified by winder on Apr. 25 2001
// shenliwan.c 神力丸

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "神力丸" NOR, ({ "shenli wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顆園園的神力丸，據說喫了可以增強膂力。\n");
		set("value", 10000);
		set("unit", "顆");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

	if (! id(arg))
		return notify_fail("你要喫什麼？\n");

	me = this_player();
	message_vision("$N一仰脖，吞下了一顆" + this_object()->name() +
		       "。\n", me);
	if (me->query("gift/shenliwan") >= 5)
	{
		message_vision("$N眨眨眼。\n", me);
		tell_object(me, "你覺得這藥沒啥味道，還不如花生好喫。\n");
	} else
	if (random(5) == 0)
	{
		tell_object(me, "不過你覺得好像沒什麼作用。\n");
	} else
	{
		tell_object(me, HIR "你覺得雙臂幾乎爆裂，充滿了力量。\n" NOR);
		me->add("str", 1);
	}

	me->add("gift/shenliwan", 1);
	destruct(this_object());
	return 1;
}
