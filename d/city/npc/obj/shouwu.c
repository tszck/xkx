// shouwu.c 何首烏

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name("何首烏", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "這是一棵初具人形的何首烏。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

//	this_player()->add("max_neili", 10);
	this_player()->set("eff_qi", this_player()->query("max_qi"));
	message_vision("$N喫下一棵何首烏，頓時間覺得全身充滿了活力 !\n", this_player());
	destruct(this_object());
	return 1;
}

