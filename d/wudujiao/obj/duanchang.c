// duanchang.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("斷腸草", ({"duanchang cao","cao" }));

                set("unit", "株");
                set("long", "這是一株閃爍着磷光的小草。\n");
                set("value", 100);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(50);


        setup();
}

