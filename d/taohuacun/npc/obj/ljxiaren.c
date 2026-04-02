#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"龍井蝦仁"NOR, ({"ljxiaren"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "釅釅濃濃的一盤龍井蝦仁。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("cook_msg", "
$N將河蝦洗淨，擠出蝦仁，用蛋清、精鹽、濕澱粉漿好；
取龍井新茶少許，用沸水沏泡；漿好的蝦仁用四成熱的大油
滑熟，再烹上茶葉、茶汁、紹酒翻炒。\n\n"
		);                
        }
}
