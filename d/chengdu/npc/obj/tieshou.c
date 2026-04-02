// Room: /d/chengdu/npc/obj/tieshou.c
// Last Modifyed by Winder on Jan. 4 2002

#include <armor.h>
inherit HANDS;

void create()
{
	set_name( "鐵手掌", ({ "iron hand", "hand" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "塊");
		set("long", "這是一塊鐵質的手掌形護具，用以保護手掌。\n");
		set("value", 900);
		set("armor_prop/armor", 1 );
	}
	setup();
}
