// Obj: /d/lingxiao/obj/bottle.c 花瓶
// Last Modified by winder on Jul. 15 2001

inherit ITEM;

void create()
{
	set_name("花瓶", ({ "bottle", "hua ping", "bag" }));
	set_weight(500);
	set_max_encumbrance(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "尊");
		set("long","一尊用萬年寒玉所制的花瓶，晶瑩剔透，光潔無比，幾枝梅花插在裏面，芳香四溢。\n");
		set("value", 0);
	}
}

int is_container() { return 1; }

