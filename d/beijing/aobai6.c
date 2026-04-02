// Room: /beijing/aobai6.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "鰲拜臥房");
	set("long", @LONG
這是鰲拜的臥房。鰲拜躺在牀上睡着了，粗聲粗氣地打着呼嚕。
北邊有一扇門(door)。
LONG );
	set("exits", ([
		"east" : __DIR__"aobai4",
		"north" : __DIR__"aobai10",
	]));
	set("item_desc", ([
		"door" : "這是一扇極厚的木門。\n",
	]));
	set("objects", ([
		__DIR__"npc/aobai" : 1,
	]));
	create_door("north", "木門", "south", DOOR_CLOSED);
	set("coor/x", -203);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
