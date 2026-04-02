#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIW "白虎賜元丹" NOR, ({ "baihu dan", "baihu", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "這是一顆純白無暇的藥丸，據説喫了可以增強膂力。\n" NOR);
                set("unit", "顆");
                set("value", 50000);
                set("weight", 50);
                set("gift_type", "str");
                set("gift_name", "先天膂力");
                set("gift_point", 65);
                set("gift_msg", HIY "突然間你只覺雙臂幾乎爆裂，充滿了力量。\n" NOR);
        }
        setup();
}

