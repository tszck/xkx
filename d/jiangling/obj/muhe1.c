//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"木盒"NOR, ({"mu he", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"這木盒古樸典雅，沉甸甸的，裏面也許有什麼寶貴的物事。\n"NOR);
		set("unit", "個");
		set("open_count", 0);
		set("weight", 20000);
	}
}

void init()
{
	add_action("do_open","open");
}

int do_open()
{
	return notify_fail("木盒已經被別人打開過了。\n");
}
