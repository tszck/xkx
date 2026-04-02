// Room: /d/mingjiao/midao0.c
// Date: Java 97/04/9

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "甬道");
	set("long", @LONG
這是一條小小的甬道，周圍都是石壁，極為堅硬，看來不是什麼武
功能打破的。向外的石門早已悄然合上，你只有鼓勇向前。
LONG );
	set("exits", ([
		"north" : __DIR__"midao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 1070);
	set("coor/z", 90);
	setup();
	create_door("north", "石門", "south", !DOOR_CLOSED);
	replace_program(ROOM);
}
