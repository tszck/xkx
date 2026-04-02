#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(WHT "玄武鑄骨丹" NOR, ({ "xuanwu dan", "xuanwu", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "這是一顆堅硬無比黑色丹藥，據説喫了可以增強根骨。\n" NOR);
                set("unit", "顆");
                set("value", 50000);
                set("weight", 50);
                set("gift_type", "con");
                set("gift_name", "先天根骨");
                set("gift_point", 65);
                set("gift_msg", HIY "你渾身的骨骼登時嘩啦啦的響個不停，可把你嚇壞了，"
				"好在一會兒就停了下來，似乎筋骨更靈活了。\n" NOR);
        }
        setup();
}

