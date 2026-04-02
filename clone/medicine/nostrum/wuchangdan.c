//wuchangdan.c
#include <ansi.h>
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
	set_name(HIR"無常丹"NOR, ({"wuchang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顆");
		set("long", "這是一顆晶瑩火紅的無常丹，經桃花島主精心練制，
有起死回生之功。\n");
		set("value", 50000);
	}
	set("pour_type", "1");
	setup();
}

int do_eat(string arg)
{
 
 int force_limit, neili_limit, force_skill;
 

	object me = this_player();

	force_limit = me->query_skill("force", 1)*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);

	if (!id(arg)) return notify_fail("你要喫什麼？\n");
	if (!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if (me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	if(me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") )
	{
		message_vision(HIG"$N喫下一隻無常丹，只覺全身冰涼，看來你補藥喫太多了，鬧起肚子來了！\n" NOR, me);
		me->receive_damage("jing",30);
		me->receive_damage("qi",50);
		me->receive_wound("jing",20);
		me->receive_wound("qi",40);
	}
	else
	{
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		message_vision(HIR"$N喫下一顆無常丹，一股熱流從丹田升起，頓時全身充滿力量！\n"NOR,me);
	}
	destruct(this_object());
	me->start_busy(2);
	return 1;
}
