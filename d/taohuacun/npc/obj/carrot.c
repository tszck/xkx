
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"胡蘿蔔"NOR,({"carrot","huluobo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一籃胡蘿蔔。\n");
                set("unit", "籃");
        }
}