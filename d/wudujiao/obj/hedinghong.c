// hedinghong.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("鶴頂紅", ({"heding hong","hong" }));

                set("unit", "瓶");
                set("long", "這是一瓶劇毒的粉末。\n");
                set("value", 100);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(50);


        setup();
}

