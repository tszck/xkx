#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY "斑鳩" NOR,({"banjiu"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一隻小斑鳩。\n");
                set("unit", "只");
        }
}