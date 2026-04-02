//Room: /d/foshan/street2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","佛山鎮街");
	set("long",@LONG
佛山鎮街道橫亙東西。南邊有一座破敗的廟宇，裏面是一家賭
場，大門上寫着“英雄會館”四個大字。
LONG);
	set("objects", ([
	    "/d/city/npc/liumang": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south" : __DIR__"huiguan",
	    "west"  : __DIR__"street1",
	    "east"  : __DIR__"street3",
	]));
	set("coor/x", -1500);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
