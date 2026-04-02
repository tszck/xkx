// fugu.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("腐骨草", ({"fugu cao","cao" }));

                set("unit", "株");
                set("long", "這是一株普通的小草，葉面發出一股難聞的臭氣。\n");
                set("value", 100);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(50);


        setup();
}

