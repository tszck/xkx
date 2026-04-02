
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC "清燉蟹粉獅子頭" NOR, ({"shizitou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗肥嫩異常，入口即化的清燉蟹粉獅子頭。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N先用豬肋條肉，分別切成石 榴粒狀，再混合起來粗略地
[贊刂]一[贊刂]，加上蔥薑汁、蟹肉、蝦子、精鹽、 紹酒、
幹澱粉調拌均勻，直至“上勁”。用熟豬油擦抹沙鍋底，將
青菜葉排在 底中，放入豬肉湯燒沸，然後將拌均勻的肉餡
放入手掌中，雙手來回滾動團成 光滑的肉圓，逐個排在菜心
上，每個再嵌上蟹黃，蓋上青菜葉，燒沸後，移在微火上燜
約一個時辰，掀去青菜葉。\n\n"
		);                
        }
}
