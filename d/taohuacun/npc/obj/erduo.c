#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC "小豬耳朵" NOR,({"erduo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一塊小豬耳朵。\n");
                set("unit", "塊");
        }
}