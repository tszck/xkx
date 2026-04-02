#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name( HIY "增慧丹" NOR, ({ "zenghui dan", "zenghui", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "這是一顆通體金黃的藥丸，據說喫了可以增強悟性。\n" NOR);
                set("unit", "顆");
                set("value", 10000);
                set("weight", 50);
                set("gift_type", "int");
                set("gift_name", "先天悟性");
                set("gift_point", 40);
                set("gift_msg", HIG "一股火熱驀然從腦中升起，"
			    "你頭痛欲裂，恰在此時一股清涼之意油然而起，頓感舒泰無比。\n"NOR);
        }
        setup();
}

