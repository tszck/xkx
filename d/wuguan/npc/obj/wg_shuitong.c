#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("水桶", ({ "shuitong" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "這是一個用圓木圈成的水桶，普通百姓的日常務農用品。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N 挑起$n擋在肩上。\n");
		set("unwield_msg", "$N將肩上的$n放了下來。\n");
	}
	init_hammer(4);
	setup();
}
