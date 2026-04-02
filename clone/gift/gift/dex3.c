#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIR "破陽無極仙丹" NOR, ({ "wuji xiandan", "wuji",
                                                  "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "傳說此丹乃是天宮中的神品，凡人喫了可以平增身法。\n" NOR);
                set("unit", "顆");
                set("value", 100000);
                set("weight", 50);
                set("gift_type", "dex");
                set("gift_name", "先天身法");
                set("gift_point", 85);
                set("gift_msg", HIW "突然你只覺全身輕飄飄的，有股騰雲駕霧的感覺。\n" NOR);
        }
        setup();
}

