
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL "黃瓜" NOR,({"cuke","huanggua"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一籃黃瓜。\n");
                set("unit", "籃");
        }
}