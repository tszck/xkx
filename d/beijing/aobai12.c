// /d/beijing/aobai12.c
// Last Modified by winder on Jan. 18 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "東廠暗道");
	set("long", @LONG
這是一條暗道，是專爲鰲拜從鰲府直接到東廠用的。
LONG );
	set("exits", ([
		"southwest" : __DIR__"aobai11",
		"northeast" : __DIR__"bingqiku",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
