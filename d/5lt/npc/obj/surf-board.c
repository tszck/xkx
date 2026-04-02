// surf-board.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("衝浪板", ({"surf board", "board"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "雙");
		set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲從懷中掏出一隻$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n揣回懷裏。\n");
        }
        init_dagger(50);
        setup();
}

