// Room: /d/chengdu/xiaoxiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
這裏是西門邊上一條幽深的小巷，不知道通向那裏。這裏不時地有
本地居民走過，你也許可以向他們打打聽聽。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"south"     : __DIR__"xijie",
		"northeast" : __DIR__"path1",
	]));

	set("coor/x", -8080);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

