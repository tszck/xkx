
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("草魚",({"caoyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一尾活蹦亂跳的草魚。\n");
                set("unit", "尾");
        }
}