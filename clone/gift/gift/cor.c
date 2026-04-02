#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( WHT "膽識丹" NOR, ({ "danshi dan", "danshi", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一顆膽識丹，聽說喫了可以增加膽識。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "cor");
                set("gift_name", "先天膽識");
                set("gift_point", 75);
                set("gift_msg", HIM "你覺得身體發生了一些變化，但隨即又平和了下來。\n" NOR);
        }
        setup();
}

