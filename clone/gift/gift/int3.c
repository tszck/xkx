#include <ansi.h>
inherit __DIR__"gift";

void create()
{
        set_name(HIW "神恩通慧仙丹" NOR, ({ "tonghui xiandan", "tonghui",
                                                  "xiandan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "傳說此丹乃是天宮中的神品，凡人喫了可以平增悟性。\n" NOR);
                set("unit", "顆");
                set("value", 100000);
                set("weight", 50);
                set("gift_type", "int");
                set("gift_name", "先天悟性");
                set("gift_point", 85);
                set("gift_msg", HIG "一股火熱驀然從腦中升起，"
			    "你頭痛欲裂，恰在此時一股清涼之意油然而起，頓感舒泰無比。\n"NOR);
        }
        setup();
}

