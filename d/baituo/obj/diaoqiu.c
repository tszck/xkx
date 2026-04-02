// diaoqiu.c
// Last Modified by Winder on May. 15 2001
 
#include <armor.h>
 
inherit NECK;
 
void create()
{
	set_name("貂裘", ({ "diao qiu", "qiu" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "silk");
		set("unit", "襲");
		set("long", "這是一襲珍貴的紫貂皮毛做的貂裘。\n");
		set("value", 20000);
		set("armor_prop/dodge", 5);
	}
	setup();
}
