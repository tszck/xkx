// Room: /d/baituo/cave1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","巖洞內");
	set("long", @LONG
這裏是巖洞內部，洞頂上懸掛着潔白的鐘乳石。
LONG	);
	set("exits",([
		"south" : __DIR__"cave",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50040);
	set("coor/y", 20080);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}


