// wg_shilu-2.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一條石板路上，東面和西面都是習武堂，不少人在這裏進進
出出的，南面是武館大廳。
LONG);
	set("exits", ([
		"southup" : __DIR__"wg_dating",
		"north"   : __DIR__"wg_shilu-4",
		"east"    : __DIR__"wg_xiwutang",
		"west"    : __DIR__"wg_xiwutang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_qzdaotong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

