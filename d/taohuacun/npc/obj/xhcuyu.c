#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"西湖醋魚"NOR, ({"xhcuyu"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤清甜可人的西湖醋魚，用西湖中的金色鯉魚
燒製而成，是西湖第一名菜。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 20);
                set("cook_msg", "
$N先將餓養兩天,已排除泥土味的鯉魚宰殺後，去掉鱗、鰓和內臟，
洗淨，從頭至尾片成兩片，再坡刀剞上刀紋，放入 沸水中稍煮，用
筷子扎魚的頜下部，能輕輕扎入時即撈出，魚背相對裝入盤內。用
煮魚的湯水適量，加入醬油、醋、紹酒、白糖，燒開後，淋入濕澱粉，
推攪成米湯汁，澆在魚身上。\n\n"
		);                
        }
}
