#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( HIR "朱雀玲瓏丹" NOR, ({ "zhuque dan", "zhuque", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "這是一顆有着血色光澤的藥丸，據說喫後可增強身法。\n" NOR);
                set("unit", "顆");
                set("value", 50000);
                set("weight", 50);
                set("gift_type", "dex");
                set("gift_name", "先天身法");
                set("gift_point", 65);
                set("gift_msg", HIW "突然你只覺全身輕飄飄的，有股騰雲駕霧的感覺。\n" NOR);
        }
        setup();
}

