#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED "豬肉" NOR,({"meat"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一塊豬肉。\n");
                set("unit", "塊");
        }
}