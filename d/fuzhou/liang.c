// room: liang.c

#include <room.h>

inherit ROOM;

void create()
{ 
	set("short","密室房梁");
	set("long", @LONG
你現在在密室的房樑上四下觀瞧，周圍都是些爛木頭破磚瓦。突然
你瞟見犄角旮旯處有一件袈裟。
LONG );
	set("exits", ([
		"down" : __DIR__"mishi",
	]));       
	set("objects", ([
		__DIR__"obj/jiasha" : 1,
		"/d/xingxiu/npc/snake" :1,
	]));       
	set("coor/x", 1820);
	set("coor/y", -6312);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
