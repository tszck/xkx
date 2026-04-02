
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"麻婆豆腐"NOR, ({"mpdoufu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗色深味厚，麻辣燙鹹的麻婆豆腐。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N把炒鍋置中火上，下菜油燒至五成熟時下肉餡，肉炒幹水氣後，下豆瓣，
炒出香味，放鹽，醬油，同時摻湯，下豆腐。豆腐下鍋後燒約三分鐘下蔥，
蔥一熟，就用水澱粉勾芡，起鍋裝碗，菜面上撒上花椒麪。\n\n"
		);
        }
}
