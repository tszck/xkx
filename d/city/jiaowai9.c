// Room: /d/city/jiaowai9.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
揚州郊外的茂密樹林，陰森可怖。抬頭不見天日。這裏也是揚州命
案發生最多的地方。鳥獸蛇蟲遊蕩不窮。
LONG );
	set("exits", ([
		"east"  : __DIR__"jiaowai8",
		"west"  : __DIR__"jiaowai10",
	]));
	set("objects", ([
		__DIR__"obj/shuzhi": 2,
		__DIR__"npc/dushe" : 1,
	]));
	set("coor/x", 30);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}