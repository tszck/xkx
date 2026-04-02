// Room: bobingting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "搏餅廳");
	set("long", @LONG
這裏是搏餅廳，也是「俠客行一百」玩家們聚會的地方。每逢大日
子，新老玩家們都會趕來這裏，大俠小蝦一塊兒熱熱鬧鬧地樂一樂。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("objects", ([
		__DIR__"player/fandog": 1,
	]));
	set("exits", ([
		"west"  : __DIR__"bobing1",
		"east"  : __DIR__"bobing2",
		"north" : __DIR__"duchang",
		"south" : __DIR__"bobing3",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
