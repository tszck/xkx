inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIC "黑玉斷續膏" NOR, ({"heiyugao"}));
	set("unit", "粒");
	set("long", "這是一粒千年極其難配製的的黑玉斷續膏，據說能起死回生。\n");
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
	this_player()->set_temp("nopoison", 1);
	this_player()->receive_curing("jing", 200);
	this_player()->recieve_curing("qi", 200);
	tell_object(this_player(), HIG "你只覺一股熱流在七經八脈中循環了一個周天，立刻神采奕奕了！\n" NOR );
	destruct(this_object());
	return 1;
}
