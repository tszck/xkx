#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( YEL "定力丹" NOR, ({ "dingli dan", "dingli", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一顆定力丹，據說喫了可以增加定力。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "cps");
                set("gift_name", "先天定力");
                set("gift_point", 75);
                set("gift_msg", HIM "你覺得身上發生了奇異的變化，但隨即又平和了下來。\n" NOR);
        }
        setup();
}

