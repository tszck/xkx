#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG "好逑湯" NOR, ({"haoqiutang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗碧綠的清湯中浮着數十顆殷紅的櫻桃，又飄着七八片粉紅色的花瓣，
底下襯着嫩筍丁子，紅白綠三色輝映，鮮豔奪目。\n");
		set("unit", "碗");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N取出十餘枚櫻桃，去核，以斑鳩肉嵌之，將其與桃花瓣、筍尖投入事
先用荷葉熬成的清湯中，用微火燜上片刻。\n\n");		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "好逑湯",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

