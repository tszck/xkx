
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW "栗子扒白菜" NOR, ({"lizibaicai"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤栗子扒白菜。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N將津白洗淨切大段,栗子去殼用清水煮至略透,濾幹水份。
再將冬菇浸軟洗淨去蒂。燒熱油約兩湯匙,將津白放下炒軟,
加入調味料、冬菇、栗子、金筍片文火煮至熟透。用少許
生粉水打芡。\n\n"
		);                
        }
}
