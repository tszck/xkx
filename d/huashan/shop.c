//Room: /d/huashan/shop.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "山頂小店");
	set("long", @LONG
這裏是華山山頂的一間小店，賣些簡單的飲食，專門賺那些遊客的
錢。
LONG );
	set("exits", ([
		"east" : __DIR__"square",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	set("coor/x", -870);
	set("coor/y", 200);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
