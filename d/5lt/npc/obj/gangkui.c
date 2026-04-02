// gangkui.c 鋼盔
 
#include <armor.h>
 
inherit HEAD;
 
void create()
{
	set_name("鋼盔", ({ "helmet", "gangkui" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "頂");
		set("long", "這是一頂嶄新的鋼盔，用以保護頭部。\n");
		set("value", 10000);
		set("armor_prop/armor", 30);
	}
	setup();
}