// Room: /d/baituo/dongjie.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "東街");
	set("long", @LONG
這裏是小鎮的東街。南邊有個打鐵鋪，裏面傳來丁丁當當的聲音。
東南方是荒涼的戈壁，東北方有條小路可上山。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"west"      : __DIR__"xijie",
		"south"     : __DIR__"datiepu",
		"southeast" : __DIR__"gebi",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/playboy" : 1,
	]));
	set("coor/x", -49980);
	set("coor/y", 19980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
