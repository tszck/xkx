// sanhuangwan.c 三黃寶蠟丸

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"三黃寶蠟丸"NOR, ({"sanhuang baolawan", "wan"}));
	set("unit", "粒");
	set("vegetable", 104);
	set("nostrum", 51);
	set("level", 140);
	set("value", 10000);
	set("long", "這是一粒三黃寶蠟丸，由麻黃、藤黃、雄黃三味主藥配製成。\n");
	set("pour_type", "1");
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

	if ( me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") )
	{
		message_vision("$N沒必要喫三黃寶蠟丸。\n",me);
	}
	else
	{
		me->receive_curing("jing", 50);
		me->receive_curing("qi", 100);
		message_vision("$N喫下一粒三黃寶蠟丸，感到丹田一股熱氣蓬勃而起，直衝全身各處經脈。\n",me);
		destruct(this_object());
	}
	return 1;
}
