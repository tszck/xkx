// chuanxin.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("穿心蓮", ({"chuanxin lian","lian" }));

                set("unit", "朵");
                set("long", "這是一朵粉紅色的蓮花。\n");
                set("value", 500);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(50);


        setup();
}

