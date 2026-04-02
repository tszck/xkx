// wg_zhangfang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "帳房");
	set("long", @LONG
這裏是武館內的一個帳房，室內一個帳房先生在這裏認真地做着帳。
武館內的大小收支都在這裏打理。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_fan" : 1,
		__DIR__"npc/wg_huashandizi" : 1,
	]) );
	
	set("coor/x", 31);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


