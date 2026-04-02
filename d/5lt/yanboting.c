// Room: /d/5lt/yanboting.c

inherit ROOM;

void create()
{
	set("short", "演播廳");
	set("long", @LONG
這裏是電視臺的多功能演播廳。導播、攝像、燈光、主持、嘉賓，
一個個忙得不可開交。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"down"      : __DIR__"mishuchu",
		"east"      : __DIR__"sheyingpeng",
		"northeast" : __DIR__"houtai",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
