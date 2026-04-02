#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIC "靈性丹" NOR, ({ "lingxing dan", "lingxing", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一顆靈性丹，據説喫了可以增加靈性。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "spi");
                set("gift_name", "先天靈性");
                set("gift_point", 75);
                set("gift_msg", HIM "你覺得身上發生了奇異的變化，但隨即又平和了下來。\n" NOR);
        }
        setup();
}

