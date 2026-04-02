#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是條長長的走廊。四處黑沉沉的。
LONG );
	set("exits", ([
		"north" : __DIR__"zhuang9",
		"south" : __DIR__"zhuang5",
	]));
	set("objects", ([
		__DIR__"npc/dizi": 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
