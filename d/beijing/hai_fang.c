// /beijing/hai_fang.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "海澄公府廂房");
	set("long", @LONG
這裏是海澄公府的左側的一個廂房，供給海澄公府的客人居住。
LONG );
	set("exits", ([
		"east" : __DIR__"hai_dayuan",
	]));

	set("sleep_room", "1");
	set("no_clean_up", 0);
	set("coor/x", -240);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
