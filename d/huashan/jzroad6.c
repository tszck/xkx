// Room: /d/huashan/jzroad6.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "樹林外");
	set("long", @LONG
樹林外，赫然站着一個漢子，在陰森森的林子邊上，憑添一股煞氣。
西上是登山的路，東邊就進入森林了。
LONG );
	set("outdoors", "zhongtiao");
	set("exits", ([ /* sizeof() == 4 */
	    "enter"   : __DIR__"jzroad5",
	    "westup"  : __DIR__"jzroad7",
	]));
	set("objects", ([
	     CLASS_D("huashan") + "/cheng-buyou": 1,
	]));

	set("coor/x", -920);
	set("coor/y", 190);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
