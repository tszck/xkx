
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "宮爆雞丁" NOR, ({"gbjiding"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗鮮香細嫩，辣而不爆，略帶甜酸的宮爆雞丁。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N取嫩公雞脯肉，穿上花刀切成方丁，用醬油、精鹽、
溼澱粉上漿，放入乾紅辣椒、花椒油中炒散，加入蔥、
姜、蒜、熟花生米，再烹上糖、醋、 鹽、味精、肉
清湯和成的芡汁。\n\n"
		);                
        }
}
