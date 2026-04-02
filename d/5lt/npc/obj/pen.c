// huabi.c

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("畫筆", ({ "huabi", "bi", "dagger" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "這是傳説中馬良用過的神筆。\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲從懷中掏出一隻$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n揣回懷裏。\n");
        }
        init_dagger(50);
        setup();
}

