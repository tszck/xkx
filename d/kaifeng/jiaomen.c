// /kaifeng/jiaomen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "角門");
	set("long", @LONG
在牆角邊開的一個小門，供寺中的僧人就近出外。門是用松木作的，
原先的紅漆已經剝落得差不多了。一邊的圍牆蹋了半邊，尋常人都能爬
進來，南邊是片菜地，出了角門是條大街。
LONG
	);
	set("objects", ([
		__DIR__"npc/zhangsan" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"caidi5",
		"north" : __DIR__"eroad0",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
