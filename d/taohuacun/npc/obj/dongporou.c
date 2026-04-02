
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"東坡肉"NOR, ({"dongporou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗香噴噴的東坡肉，用文火煨肥豬肉而成，
蘇東坡在牧守杭州時看到民間喫肉而燒製不得法，遺惠此法至千年以下。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 10);
                set("food_supply", 100);
                set("cook_msg", "
$N將淨豬五花肋肉切方形肉塊，下沸水鍋中稍煮。然後在大砂鍋中鋪上
蔥和姜塊，下入煮過的豬肉，加調料蓋好鍋蓋，並用紗紙封縫。將砂鍋
置旺火上，燒開後改用微火燜二小時，把肉塊翻身，再加蓋密封，用微
火燜二小時，把肉塊翻至酥爛，倒入陶罐中再用旺火蒸。\n\n"
		);                
        }
}
