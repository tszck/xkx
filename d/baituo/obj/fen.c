//fen.c

inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "use");
}

void create()
{
	set_name("蛇膽粉", ({ "fen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "這是療傷的『蛇膽粉』。\n");
		set("value", 2000);
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

	if ((int)this_player()->query("eff_qi") >=
		(int)this_player()->query("max_qi"))
		return notify_fail("你現在不需要用蛇膽粉。\n");
	if(random(2)==0)
	{
		message_vision("$N喫下一包蛇膽粉，覺得象是土豆粉，連呼上當￣￣\n" , me);
	}
	else
	{
		me->add("qi",30);
		me->add("eff_qi",20);
		message_vision( "$N喫下一包蛇膽粉，頓覺真氣上湧，精神好了些。\n" , me);
	}
	destruct(this_object());
	return 1;
}
