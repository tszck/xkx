// ruzhu.c 片皮乳豬

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "片皮乳豬" NOR, ({"ruzhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
//		set("long", "雞豆花色白細嫩，湯清味鮮，源於豆花，高於豆花，
//被譽名爲“豆花不用豆，喫雞不見雞”的佳餚美饌。\n");
		set("long","片皮乳豬是廣東地方代表菜之一。傳統的“燒乳豬”在燒烤過程
中，加入麥芽糖起焦化着色作用，加入白醋起脆皮作用，而最重
要的是加入了白酒起到了酥化的效果，製作成了“麻皮乳豬”。
“麻皮乳豬”有兩種上菜方法，一爲“片皮”，一爲“斬件”，
前者跟甜醬、千層餅、細砂糖和蔥球，後者跟甜醬和細砂糖即可。\n");
		set("unit", "只");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}