// Room: /d/suzhou/nandajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在一條繁華的街道上，向南北兩頭延伸。北邊通往城南大街的
中心地段，東面是聽雨軒，西面是留園，望南面，是蘇州城的南城門。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"tingyu",
		"west"  : __DIR__"liuyuan",
		"north" : __DIR__"nandajie1",
		"south" : __DIR__"nanmen",
	]));
	set("coor/x", 850);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
