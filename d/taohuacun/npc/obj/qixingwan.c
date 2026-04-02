#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW "七星丸" NOR, ({"qixingwan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗鮮湯。湯清如鏡，魚丸漂浮在湯的面上，潔白如星斗，因此稱為“七星丸”。\n");
		set("unit", "碗");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N將魚肉用刀背剁成泥，剁好後加清水用力攪勻，再加鹽繼續攪至魚肉泡漲起。
$N將豬腿肉去皮去筋，同蝦仁混合一起，剁成細末，加鹽 少許拌和。然後用
左手將魚肉泥從拇指與食指之間捏擠出一隻只的小丸子，右手隨 即用極少的
豬肉蝦仁末塞入魚丸裏。這樣一隻只邊裹邊放入清水鍋內燒熟。然後另用淨乾鍋，
倒入清雞湯，再從清水鍋中將魚丸撈出，放 入清湯鍋內燒開後連湯帶魚丸舀入
湯碗，撒上芹菜末，胡椒粉，澆上麻油。\n\n"
		);		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "七星丸湯",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

