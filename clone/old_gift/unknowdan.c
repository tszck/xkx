// Last Modified by winder on Apr. 25 2001
// unknow.c 未名仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "仙丹" NOR, ({ "dan", "xian dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一顆園園的火紅仙丹，不知道有什麼用處。\n");
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
	if (me->query("gift/unknowdan") >= 5)
	{
		message_vision("$N搖搖晃晃的，突然“啪嗒”一下子摔了個跟頭。\n", me);
		tell_object(me, "你覺得喫完以後頭重腳輕的。\n");
	} else
	if (random(5) == 0)
	{
		tell_object(me, "不過你覺得好像沒什麼作用。\n");
	} else
	{
		tell_object(me, HIM "霎時間你覺得腿骨欲裂，一時疼痛難忍，暈了過去。\n" NOR);
		me->add("dex", 1);
		me->unconcious();
	}

	me->add("gift/unknowdan", 1);
	destruct(this_object());
	return 1;
}
