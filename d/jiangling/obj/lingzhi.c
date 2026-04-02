//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIG"靈芝"NOR, ({"lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "這是一棵靈芝，是湖北出產的名貴中藥。\n");
		set("value", 20000);
	}
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
	if(arg=="lingzhi") 
	{
		me->set("jing",me->query("max_jing"));
		me->set("qi",me->query("max_qi"));
		message_vision(HIG"$N喫下一棵靈芝，頓時覺得渾身充滿了活力！\n"NOR,me);
		me->start_busy(1);
		destruct(this_object());
	}
	return 1;
}

