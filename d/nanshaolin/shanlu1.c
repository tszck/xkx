// Room: /d/nanshaolin/shanlu1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "丘陵山路");
	set("long", @LONG
福建境內，四季如春。只見滿山紅花，蝴蝶飛舞。你走在丘陵山路
上。四處張望，順手拔些小草芯含在嘴裏，清清的味道，以前從沒有這
樣喫過，感覺真好。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east" : "/d/fuzhou/puxian",
		"west" : __DIR__"ting",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

