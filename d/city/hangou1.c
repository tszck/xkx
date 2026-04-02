// Room: /city/hangou1.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "古邗溝邊");
	set("long", @LONG
沿古邗溝繼續東行，可以看到水面上有許多官船和富商的包船，船
中不時傳出陣陣嬉笑之聲。與這些船同行的還有許多喫水深不少的貨船，
這大抵是北貨運到揚州來出售的，也有是淮南的土產。不少鹽船把各地
鹽場收來的鹽運送到這個淮南東路的治所來，使得這裏的水面擁擠不堪。
LONG );
	set("exits", ([
		"west" : __DIR__"hangou2",
		"east" : __DIR__"hangou0",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

