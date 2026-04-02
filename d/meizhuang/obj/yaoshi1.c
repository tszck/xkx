// yaoshi.c
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"鋼芯鑰匙"NOR, ({"gang yaoshi", "yaoshi"}));
	set("long", "這是一把鋼芯鑰匙，看起來非常堅固。\n");
	set("unit", "把");
	set("weight", 10);
}

