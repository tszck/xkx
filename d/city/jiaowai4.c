// Room: /d/city/jiaowai4.c
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
		"north"	 : __DIR__"jiaowai3",
		"west"	  : __DIR__"jiaowai5",
		"southeast" : "/d/yixing/shulin1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/zhao-gouer" : 1,
		__DIR__"obj/shuzhi": 2,
		__DIR__"obj/shitou": 2,
	]));
	set("coor/x", 70);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
