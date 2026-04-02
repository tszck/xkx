
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "滷豆腐" NOR, ({"ludoufu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤散發着濃香的滷豆腐。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                set("cook_msg", "
$N將黃豆腐完整地放在冷水鍋裏，蓋好鍋蓋，用旺火煮到豆腐出現
許多小孔。形如蜂窠狀時取出。再將豬排用開水川一下，以拔去
血水。然後起淨乾鍋，將豆腐放入，再將豬排放在豆腐上面，加清
湯、醬油、糖、用小溫火燒約二十分鐘，最後將豆腐取出，切成片。\n\n"
		);                
        }
}
