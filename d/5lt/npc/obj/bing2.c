// bing2.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("紅豆餅", ({ "hongdou bing2","bing2"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一塊剛出爐，熱氣騰騰的紅豆餅。\n");
		set("unit", "塊");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
	setup();
}
