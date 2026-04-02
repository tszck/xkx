// Room: /d/tiezhang/hhyuan1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "後花園");
	set("long", @LONG
這是一處環境優雅的花園。只見喬松修竹，蒼翠蔽天，層巒奇岫，
靜窈幽深。西面有一座假山，東面是一大片的花圃。北面是通往山上的
路。
LONG	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"shanlu3",
		"south" : __DIR__"hxfang",
		"east"  : __DIR__"hhyuan2",
		"west"  : __DIR__"hhyuan3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1940);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}