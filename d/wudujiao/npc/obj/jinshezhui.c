// jinshechui.c 金蛇錘

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("金蛇錘", ({ "jinshe chui", "chui","hammer" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "這是一柄金光閃閃的錘柄呈蛇形的大鐵錘，後面帶着長長
奶礎n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N「譁啷」的一聲,取出一柄$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n掛回腰間。\n");
	}
	init_hammer(80);
	setup();
}
