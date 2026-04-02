#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC "鮮菜香菇" NOR, ({"xcxianggu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盤清淡，但囗味卻還不錯的鮮菜香菇。\n");
                set("unit", "盤");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                set("cook_msg", "
$N把香菇用冷水略沖洗乾淨後，用開水發開。切成條。 
然後冷鍋起油，加入少許蠔油略炒，加入青菜，翻炒至
青菜變色，加入切好的香菇，略翻炒後，加鹽調囗味，
另用髮香菇的水，調開少許芡粉，勾芡後待湯汁收濃。\n\n"
		);                
        }
}
