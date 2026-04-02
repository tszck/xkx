// Room: /d/nanshaolin/xiaolu-3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
你走在一條碎石鋪成的小路上，兩側青草茵茵，山花爛漫。空氣中夾帶
着泥土的芳香，撲面而來。南面有一片很大的菜園子。
LONG );
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"cyzi-1",
		"north" : __DIR__"xiaolu-2",
	]));
	set("coor/x", 1870);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

