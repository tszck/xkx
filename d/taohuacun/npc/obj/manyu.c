
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(WHT "鰻魚" NOR,({"manyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一條活蹦亂跳的鰻魚。\n");
                set("unit", "條");
        }
}