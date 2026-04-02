// Room: /d/chengdu/obj/box1.c 善緣箱
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("善緣箱", ({ "shanyuan xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "個");
		set("long","這是一個小廟裏常見的箱子，專門用來接受善男信女們的捐款。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

