// /d/beijing/aobai10.c
// Last Modified by winder on Jan. 18 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "東廠暗道");
	set("long", @LONG
這是一條暗道，是專爲鰲拜從鰲府直接到東廠用的。南邊是一扇木
門(door)。
LONG );
	set("exits", ([
		"south"     :  __DIR__"aobai6",
		"northeast" : __DIR__"aobai11",
	]));
	set("item_desc", ([
		"door" : "這是一扇極厚的木門。\n",
	]));
	create_door("south", "木門", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
