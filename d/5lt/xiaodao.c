// Room: /d/5lt/xiaodao.c

inherit ROOM;

void create()
{
	set("short", "鄉間小道");
	set("long", @LONG
這是條坑坑窪窪的鄉間小道，路兩旁都栽上了村裏新引進的亞熱帶
植物。往前走就到電視臺了。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"north"     : __DIR__"mubanlu",
		"southeast" : __DIR__"wroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
