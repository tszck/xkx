// jade-belt.c example belt

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( HIB "藍寶石腰帶" NOR, ({ "jade belt", "belt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set("value", 3000);
                set("material", "cloth");
                set("armor_type", "waist");
                set("armor_prop/personality", 2);
                set("armor_prop/armor", 4);
                set("armor_prop/dodge", -1);
                set("wear_msg","$N圍上一條$n。\n");
                set("remove_msg","$N將$n解了下來。\n");
        }
}
