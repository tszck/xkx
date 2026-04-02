// Room: /beijing/duchang2.c

inherit ROOM;

void create()
{
	set("short", "賭場");
	set("long", @LONG
這裏有四條走廊通向不同的房間。
LONG );
	set("exits", ([
		"east"  : __DIR__"eproom",
		"west"  : __DIR__"wproom",
		"south" : __DIR__"sproom",
		"north" : __DIR__"nproom",
		"down"  : __DIR__"duchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4060);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
