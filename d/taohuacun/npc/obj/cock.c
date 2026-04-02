#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR "公雞" NOR,({"cock"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一隻嫩公雞。\n");
                set("unit", "只");
        }
}