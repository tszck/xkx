
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "魚香肉絲" NOR, ({"yxrousi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤魚香橫溢，微帶辣味的魚香肉絲。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N將豬肉、玉蘭片、木耳均切絲，入碗中加調料稍醃。再將調料加肉湯
燒開調成芡汁。然後將肉絲下油鍋中滑炒散，加姜、蒜、泡紅椒炒出
魚香味，再下入玉蘭片、木耳絲煸炒，烹入芡汁。\n\n"
		);               
        }
}
