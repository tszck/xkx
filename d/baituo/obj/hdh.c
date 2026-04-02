#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"鶴頂紅"NOR, ({"heding hong", "hong", "heding"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long", RED"這是一個新鮮的鶴頂紅，還散發着陣陣熱氣。\n"NOR);
		set("value", 50000);
	}
	setup();
}

int init()
{
	call_out("dest", 800);
	add_action("do_eat", "fu"); 
	add_action("do_eat", "eat"); 
}

int do_eat(string arg)
{
	object me = this_player();
	int damage;

	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	message_vision("$N服下一個" + name() + "。\n", me);  
	tell_object(me, MAG "你感覺腹中一股巨疼傳來，瞬間全身火熱滾燙！\n" NOR);
	damage = (int)me->query("max_jing");
	damage = damage/15;
	damage = damage*14;
	me->receive_wound("jing", damage);
	me->receive_damage("qi", damage);

	if ((int)me->query_condition("ice_poison") > 1)
	{
		me->apply_condition("ice_poison", 1);
		return 0;
	}
	if ((int)me->query_condition("cold_poison") > 1)
	{
		me->apply_condition("cold_poison", 1);
		return 0;
	}
	me->apply_condition("hot_poison", 70); 
	destruct(this_object());
	return 1;
}

void dest()
{
	object me = this_player();
	if (present(this_object(), me))
	tell_object(me, HIR "鶴頂紅的熱氣散盡，慢慢乾枯了。\n" NOR);

	destruct(this_object());
}

