// wa.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"漢瓦"NOR, ({"han wa", "wa"}));
	set("long", "這是一片珍貴的漢瓦。\n");
	set("unit", "片");
	set("value", 500);
	set("weight", 10);
}

