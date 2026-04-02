#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(YEL"叫化童雞"NOR, ({"jhtongji"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "一隻被烤得流油，香味撲鼻的叫化雞。\n");
                set("unit", "只");
                set("value", 120);
                set("food_remaining", 1);
                set("food_supply", 100);
                set("cook_msg", "
$N把嫩母雞宰殺褪洗乾淨後，肋開取 出內臟，經用山奈、八角、
醬油、紹酒、白糖、精鹽、味精、蔥段、薑絲和成 的滷汁醃漬，
再逐層包上豬網油、荷葉、玻璃紙，用細麻繩紮好，最外面再包 
上和好的酒罈泥和泥加料酒、精鹽，烘烤兩個時辰，[扌盍]去 
泥包，蘸花椒鹽、辣醬油佐食。\n\n"
		);                
        }
}
