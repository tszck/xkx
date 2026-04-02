// Room: /d/city/jiaowai11.c
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
		"east"   : __DIR__"jiaowai10",
		"north"  : __DIR__"jiaowai13",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 2,
		__DIR__"obj/shitou": 1,
	]));
	set("coor/x", 10);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}