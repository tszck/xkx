// DOUJIANG.C 豆漿

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("豆漿",({ "jiang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯熱氣騰騰的豆漿～～～\n");
		set("unit", "杯");
		set("value", 500);
        set("max_liquid", 4);
	}
	set("liquid", ([
		"type": "water",
		"name": "豆漿",
		"remaining": 10,
		"drunk_supply": 10,
	]));
	setup();
}

