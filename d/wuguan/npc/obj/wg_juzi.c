#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("鋸子", ({ "juzi", "ju" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一用來鋸木頭的鋸子，普通百姓的日常用品。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N拿出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n扛在肩上。\n");
	}
	init_blade(4);
	setup();
}

