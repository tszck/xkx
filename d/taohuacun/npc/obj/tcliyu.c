
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "糖醋鯉魚" NOR, ({"tcliyu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤皮酥肉嫩，甜酸鮮美的糖醋鯉魚。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N將魚去鱗，開膛取內臟，挖去兩鰓，魚身兩面剞上牡丹花刀，
用 精鹽、味精醃漬後，掛一層濕澱粉糊，放入七成熱的油中炸熟，
外皮焦酥呈金黃色撈出，擺放在魚池內，再澆上用蔥、姜、蒜、
醬油、醋、白糖、精鹽、味精、清湯、澱粉製成的芡汁。\n\n"
		);                
        }
}
