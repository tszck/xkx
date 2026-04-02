#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( HIC "養顏丹" NOR, ({ "yangyan dan", "yangyan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一顆養顏丹，據說喫了可以增加容貌。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "per");
                set("gift_name", "先天容貌");
                set("gift_point", 75);
                set("gift_msg", HIM "你覺得身上發生了奇異的變化，但隨即又平和了下來。\n" NOR);
        }
        setup();
}

