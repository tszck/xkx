#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIY "幸運丹" NOR, ({ "xingyun dan", "xingyun", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一顆幸運丹，據説喫了可以增加福緣。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "kar");
                set("gift_name", "先天福緣");
                set("gift_point", 75);
                set("gift_msg", HIM "你覺得身上發生了奇異的變化，但隨即又平和了下來。\n" NOR);
        }
        setup();
}

