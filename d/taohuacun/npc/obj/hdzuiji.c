
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "花雕醉雞" NOR, ({"hdzuiji"}));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "酒香撲鼻的一隻花雕醉雞。\n");
                set("unit", "只");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 20);
                set("cook_msg", "
$N將雞洗淨除內臟，斬去雞頭雞腳。然後煮沸清水，放下薑片、
蔥段、八角，待水再度沸起，放雞入水中浸煮至熟爲爲止。再將
雞取出待冷，雞湯盛入大湯盅內，加入調味料及同份量的凍開水
拌勻，將花雕酒加入，成爲酒滷。最後將雞件取出斬成小塊，排
放上碟，淋上酒滷。\n\n"
		);                
        }
}
