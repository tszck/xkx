// baiyunwan.c 白雲熊膽丸

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("白雲熊膽丸", ({"baiyunxiudan wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顆");
		set("long", "這是一顆武林人士夢寐以求的療傷聖藥。\n");
		set("value", 50000);
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
	this_player()->receive_curing("qi", 100);
	this_player()->receive_curing("jing", 100);
	message_vision("$N喫下一顆白雲熊膽丸，只覺精氣上升，氣色大好。\n", this_player());
	destruct(this_object());
	return 1;
}

