// Room: /d/chengdu/npc/obj/wuliangye.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("五糧液", ({"wuliangye", "wu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "這是一瓶剛剛打開的五糧液，酒香撲鼻，讓人垂涎三尺。\n");
		set("unit", "瓶");
		set("value", 300);
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type": "alcohol",
		"name": "五糧液",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}

