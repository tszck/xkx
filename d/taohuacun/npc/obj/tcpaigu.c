#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED "糖醋排骨" NOR, ({"tcpaigu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盤酸甜可口的糖醋排骨。\n");
		set("unit", "盤");
		set("value", 15);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("cook_msg", "
$N把小排切塊加調味料拌勻，醃漬入味，再把洋蔥、胡蘿蔔、小
黃瓜滾刀切塊。小排入油鍋炸成金黃色取出。然後在乾淨鍋中入
油半大匙，爆香蒜屑、洋蔥，再加入胡蘿蔔、小黃瓜、炸好的小
排，拌入調味料。\n\n"
		);		
	}
}