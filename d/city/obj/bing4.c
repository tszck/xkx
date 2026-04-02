//bing4.c 三紅餅
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR "三紅餅" NOR, ({"bing4", "sanhongbing"}));
	set("unit", "個");
	set("long", "這是一個清香的三紅餅。\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要喫什麼？\n");
	if (query("owner") != me->query("id"))
	{
		write(HIR"你只能喫自個贏來的餅。\n"NOR);
		return 1;
	}
	if(arg=="bing4"||arg=="sanhongbing")
	{
		me->add("combat_exp",668);
		me->add("potential",198);
		message_vision(HIY "$N三口兩口吃下一塊$n。\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
