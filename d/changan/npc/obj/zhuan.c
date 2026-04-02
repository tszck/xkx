// zhuan.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(CYN"秦磚"NOR, ({"qin zhuan", "zhuan"}));
	set("long", "這是一塊很古舊的秦磚。\n");
	set("unit", "塊");
	set("value", 500);
	set("weight", 100);
}

