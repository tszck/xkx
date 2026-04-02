// /kaifeng/nanying.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "南盈門");
	set("long", @LONG
南盈門是開封城的南門，由於開封府尹治理有方，開封境內很是平
安。出城不遠就是禹王臺。
LONG);
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
		__DIR__"npc/walker" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"jiedao2",
		"south" : __DIR__"dadao0",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
