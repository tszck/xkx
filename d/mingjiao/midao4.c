// Room: /d/mingjiao/midao4.c
// Date: Java 97/04/9

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "石室");
	set("long", @LONG
這是一條小小的甬道，周圍都是石壁，極爲堅硬，看來不是什麼武
功能打破的。石室裏伸手不見無指，順着石壁你摸索着，好象周圍有石
門。
LONG );
	set("exits", ([
		"south" : __DIR__"midao12",
		"north" : __DIR__"midao8",
		"east"  : __DIR__"midao1",
		"west"  : __DIR__"midao3",
	]));
	set("no_clean_up", 0);
	set("no_drop", 1);
	set("coor/x", -52030);
	set("coor/y", 1070);
	set("coor/z", 90);
	setup();
	create_door("south", "石門", "north", DOOR_CLOSED);
	create_door("north", "石門", "south", DOOR_CLOSED);
	create_door("east",  "石門", "west",  DOOR_CLOSED);
	create_door("west",  "石門", "east",  DOOR_CLOSED);
	replace_program(ROOM);
}
