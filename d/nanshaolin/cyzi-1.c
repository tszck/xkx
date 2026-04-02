// Room: /d/nanshaolin/cyzi-1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "菜園子");
	set("long", @LONG
這裏是少林寺的菜園子，方圓有兩百來畝地，寺內所需的蔬菜，大
多數都是這裏產的。對於犯戒的僧人，也常被罰到這裏，做些劈柴，澆
地的苦役，已贖其過。園內正有十幾名僧人忙碌的耕做着，其中有幾人
身上居然帶着鐐銬。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"south" : __DIR__"cyzi-2",
		"north" : __DIR__"xiaolu-3",
		"east"  : __DIR__"cyzi-4",
		"west"  : __DIR__"caidi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1870);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

