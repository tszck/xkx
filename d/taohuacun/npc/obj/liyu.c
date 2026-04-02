
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY "鯉魚" NOR,({"liyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一尾活蹦亂跳的鯉魚。\n");
                set("unit", "尾");
        }
}