// Room: /d/huanggong/hubu.c

inherit ROOM;

void create()
{
	set("short", "戶部公署");
	set("long", @LONG
這裏是六部之二--戶部官員候朝的朝房.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"youmen",
	]));
	set("coor/x", -180);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}