#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG "百合冬瓜湯" NOR, ({"bhdgtang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗清新爽口，消暑去脂肪的百合冬瓜湯。\n");
		set("unit", "碗");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N把冬瓜去核洗淨連皮切件，鮮百合切開去心，清水八碗，
煲約一小時，加鹽少許。\n\n"
		);		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "百合冬瓜湯",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

