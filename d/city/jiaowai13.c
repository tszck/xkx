// Room: /d/city/jiaowai13.c
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
		"south" : __DIR__"jiaowai11",
		"east"  : __DIR__"jiaowai12",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/mo-bu" : 1,
		__DIR__"obj/shuzhi": 1,
	]));
	set("coor/x", 10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}