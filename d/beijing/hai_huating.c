// /beijing/hai_huating.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府花廳");
	set("long", @LONG
這個花廳是喝酒賞月的佳所，一個小亭子建造在廳的中央，四周圍
繞着一些葡萄藤。一陣微風吹過，空氣中似乎有隱隱的花香飄來，中人
欲醉。
LONG );
	set("exits", ([
		"west" : __DIR__"hai_dayuan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
