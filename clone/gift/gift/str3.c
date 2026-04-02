#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIY "蚩尤誅元仙丹" NOR, ({ "zhuyuan xiandan", "zhuyuan",
                                            "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "傳説此丹乃是天宮中的神品，凡人喫了可以平增膂力。\n" NOR);
                set("unit", "顆");
                set("value", 100000);
                set("weight", 50);
                set("gift_type", "str");
                set("gift_name", "先天膂力");
                set("gift_point", 85);
                set("gift_msg", HIY "突然間你只覺雙臂幾乎爆裂，充滿了力量。\n" NOR);
        }
        setup();
}

