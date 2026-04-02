//lhqdating.c
inherit ROOM;

void create()
{
	set("short", "烈火旗大廳");
	set("long", @LONG
這裏是烈火旗的大廳，廳中紅旗招展，刀槍映血，教衆絳衣赤帽，
團團擁住烈火旗掌旗使辛然。
LONG);
	set("exits", ([
		"west" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/xinran": 1,
	]));
	set("coor/x", -52020);
	set("coor/y", 1000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}