// yaoshi.c
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"紅玉鑰匙"NOR, ({"hongyu yaoshi", "yaoshi"}));
	set("long", "這是一把看起來很古怪的鑰匙。\n");
	set("unit", "把");
	set("weight", 10);
}

