// Room: /d/wizard/wizard_jail.c
// Last modified by winder 2002/10/18

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "天牢");
	set("long", @LONG
這裏就是本泥潭的巫師監獄。這裏南邊有門，可四面無窗，被關在
這裏的巫師，將被剝奪法力。既然在這裏，你就什麼也別想，還是靜心
思過吧。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"south" : "/d/death/god2",
	]));
	setup();
}

void init()
{
	object me = this_player();

	if(me->query("id") != "winder")
	{
		write(HIC"天牢"NOR
"這裏就是本泥潭的巫師監獄。這裏南邊有門，可四面無窗，被關在
這裏的巫師，將被剝奪法力。既然在這裏，你就什麼也別想，還是靜心
思過吧。
    這裏唯一的出口是 "HIW"south"NOR"。\n");
		me->set("startroom",base_name(environment(me)));
		add_action("block_cmd","",1);
	}
}

int block_cmd(string arg)
{
	if(arg != "l") return 1;
}

