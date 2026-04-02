// caoyao.c 草藥
inherit ITEM;
#include <ansi.h>
void setup()
{}
void init()
{
	add_action("do_fu", "fu");
}
void create()
{
	set_name(HIG"草藥"NOR, ({"caoyao", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "這是一片敷了療傷的普通草藥。\n");
		set("value", 100);
	}
	setup();
}
int do_fu(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("你要敷什麼藥？\n");
	if(!present(this_object(), me))
		return notify_fail("你要敷什麼藥？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢敷。\n");

	if (this_player()->query("eff_qi") == this_player()->query("max_qi"))
		return notify_fail("你現在不需要敷草藥。\n");
	else {
		this_player()->receive_curing("qi", 5);
		message_vision("$N敷了一片草藥在傷口上，感到傷勢好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}
