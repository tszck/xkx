#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(NOR + YEL "洗髓再造仙丹" NOR, ({ "xisui xiandan", "xisui",
                                                  "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "傳説此丹乃是天宮中的神品，凡人喫了可以平增根骨。\n" NOR);
                set("unit", "顆");
                set("value", 100000);
                set("weight", 50);
                set("gift_type", "con");
                set("gift_name", "先天根骨");
                set("gift_point", 85);
                set("gift_msg", HIY "你渾身的骨骼登時嘩啦啦的響個不停，可把你嚇壞了，"
				"好在一會兒就停了下來，似乎筋骨更靈活了。\n" NOR);
        }
        setup();
}

