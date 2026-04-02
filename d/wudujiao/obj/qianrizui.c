// qianrizui.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("千日醉", ({"qianri zui","zui" }));

                set("unit", "顆");
                set("long", "這是一顆核桃大小的果實，散發着一股濃鬱的酒香。\n");
                set("value", 200);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(50);


        setup();
}

