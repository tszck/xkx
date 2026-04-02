// Room: /d/henshan/hsroad5.c 林間大道
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "林間大道");
	set("long", @LONG
這裏是一條林間大道。這裏是湖南境內。南邊通向南嶺的一個
山口。路東隱隱可以看到一角城牆。西面是一座猛惡山林。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"west"     : "/d/xiakedao/mtroad1",
		"east"     : __DIR__"hsroad4",
		"north"    : __DIR__"hsroad6",
		"southup"  : __DIR__"hsroad9",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -1600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
