// huaban.c 花瓣

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIM"花瓣"NOR, ({"huaban"}));
	set_weight(500);
	set("vegetable", 16);
	set("value", 100);
	set("unit", "片");
	set("long", "這是一片粉紅的花瓣，看來剛摘下不久。\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	write("人家只有蜜蜂和蝴蝶對花瓣有興趣，原來你也......\n");
	return 1;
}
