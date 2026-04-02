// Room: /d/quanzhou/jiangjunfu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "將軍府書房");
	set("long", @LONG
這是靖海侯府的書房，裏面除了書籍之外，更多的還是各種兵刃。
LONG );
	set("exits", ([
		"south" : __DIR__"jiangjunfu",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

