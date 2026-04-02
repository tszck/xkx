#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("怪蛇之膽", ({"guai shedan", "dan", "shedan"}));
        set("unit", "只");
        set("long", "這是怪蛇的膽，圓圓的，呈深紫色，腥臭無比，不知有沒有毒。\n");
        set("value", 1000);
        setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit,food_limit,water_limit;
	object me=this_player();
	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	food_limit = me->max_food_capacity();
	water_limit = me->max_water_capacity();

	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	if (( me->query("food")>=food_limit)||(me->query("water")>=water_limit))
		return notify_fail("你已經喫飽了，再也喫不下任何一點東西。\n");
	if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 2);
		me->add("neili", 5);
	}
	message_vision(HIY "$N喫下一顆蛇膽，只覺汁液腥極苦極，難喫無比，只想噴了出去。\n" NOR, this_player());
	me->add("food",50);
	me->add("water",50);
	destruct(this_object());
	return 1;
}
