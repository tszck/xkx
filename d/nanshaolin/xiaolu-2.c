// Room: /d/nanshaolin/xiaolu-2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
你走在一條碎石鋪成的小路上，兩側青草茵茵，山花爛漫。空氣中
夾帶着泥土的芳香，撲面而來。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"south"     : __DIR__"xiaolu-3",
		"northwest" : __DIR__"xiaolu-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1870);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

