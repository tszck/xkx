#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"櫻桃"NOR,({"yingtao"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋鮮紅的櫻桃。\n");
                set("unit", "袋");
        }
}