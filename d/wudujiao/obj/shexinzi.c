// shexinzi.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("蛇信子", ({"shexin zi","zi" }));

                set("unit", "顆");
                set("long", "這是一顆植物的果實。\n");
                set("value", 100);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(50);


        setup();
}

