// jujingdan.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIY"延年聚精丹"NOR, ({"jujing dan", "dan"}));
	set("unit", "粒");
	set("vegetable", 68);
	set("nostrum", 14);
	set("level", 80);
	set("long", "這是一粒武當門下煉功用的丹藥。\n");
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
	int taoism_limit, jingli_limit;
	object me = this_player();

	taoism_limit = me->query_skill("taoism", 1)*10;
	jingli_limit = me->query("max_jingli");

	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	if ( jingli_limit <= taoism_limit ) me->add("max_jingli", 1);
	me->set("qi",me->query("eff_qi"));
	message_vision("$N喫下一粒延年聚精丹，頓覺舌底生津，氣血旺盛。\n",me);

	destruct(this_object());
	return 1;
}
