#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("瓢", ({ "piao" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一個用老葫蘆劈開做成的瓢，普通百姓的日常務農用品。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N 拿出一個$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插在腰上。\n");
	}
	init_hammer(4);
	setup();
}
