// Room: /beijing/aobai5.c


inherit ROOM;

void create()
{
	set("short", "鰲府廚房");
	set("long", @LONG
一進門，一股香氣撲鼻而來，燻得你直流口水。竈臺上滿是油煙，
一個肥肥胖胖的傢伙正在炒菜,一看就象個大廚師。
LONG );
	set("exits", ([
		"south" : __DIR__"aobai3",
	]));
	set("objects", ([
		__DIR__"npc/chushi" : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
