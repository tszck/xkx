// Last Modified by winder on Apr. 25 2001
// xiandan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "仙丹" NOR, ({ "dan", "xian dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顆園園的仙丹，據説喫了可以增強智力。\n");
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
	if (me->query("gift/xiandan") >= 5)
	{
		message_vision("$N忽然“哇哇”，吐了一地。\n", me);
		tell_object(me, "你覺得嘴裏非常的苦。\n");
	} else
	if (random(5) == 0)
	{
		tell_object(me, "不過你覺得好像沒什麼作用。\n");
	} else
	{
		tell_object(me, HIG "一股火熱驀然從腦中升起，"
			    "你頭痛欲裂，恰在此時一股清涼之意油然而起，頓感舒泰無比。\n");
		me->add("int", 1);
	}

	me->add("gift/xiandan", 1);
	destruct(this_object());
	return 1;
}
