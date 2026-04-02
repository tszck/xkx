// shanshen.c 老山叄

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("老山叄", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "這是一株沾滿山泥的長白老山叄。\n");
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
	this_player()->add("max_qi", 100);

	message_vision("$N喫下一株老山叄，只覺得渾身一股熱氣兜底冒了上來！\n", this_player());
	destruct(this_object());
	return 1;
}


