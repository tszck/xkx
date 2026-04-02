#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( WHT "壯骨粉" NOR, ({ "zhuanggu fen", "zhuanggu", "fen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一包灰黑色的藥粉，據說喫了可以增強根骨。\n" NOR);
                set("unit", "包");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "con");
                set("gift_name", "先天根骨");
                set("gift_point", 40);
                set("gift_msg", HIY "你渾身的骨骼登時嘩啦啦的響個不停，可把你嚇壞了，"
				"好在一會兒就停了下來，似乎筋骨更靈活了。\n" NOR);
        }
        setup();
}

