#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG "蝦仁" NOR,({"xiaren"}));
	set_weight(20);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一盤新鮮的河蝦蝦仁。\n");
                set("unit", "盤");
        }
}