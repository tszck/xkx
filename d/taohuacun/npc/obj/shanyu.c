#include <ansi.h>
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("鱔魚",({"shanyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一條活蹦亂跳的鱔魚。\n");
                set("unit", "條");
        }
}