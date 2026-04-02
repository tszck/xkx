#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"九黃餅"NOR, ({"jiuhuang bing","bing"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "荊州名點，酥鬆香甜。\n");
                set("unit", "塊");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

