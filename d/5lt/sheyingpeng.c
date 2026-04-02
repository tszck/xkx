// Room: /d/5lt/sheyingpeng.c

inherit ROOM;

void create()
{
	set("short", "攝影棚");
	set("long", @LONG
這裏是電視臺的攝影棚。現場人頭攢動彩旗飄揚，不知道今天是哪
位大明星作客電視臺。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"west"      : __DIR__"yanboting",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
