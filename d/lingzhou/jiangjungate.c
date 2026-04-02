// Room: /lingzhou/jiangjungate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "大將軍府");
	set("long", @LONG
這裏是徵東大將軍赫連鐵樹的府第，在東大街的正中，對面就是衙
門。一色高檐大屋，兩個校尉看上去彪悍驍勇，此刻正神氣活現的挎着
彎刀守在門前。
LONG );
	set("exits", ([
		"north" : __DIR__"dongdajie",
		"south" : __DIR__"jjdayuan",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	set("coor/x", -17950);
	set("coor/y", 32060);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && objectp(present("xiao wei", environment(me))))
		return notify_fail("校尉擋住了你的去路：大將軍不在府上！\n");

	return ::valid_leave(me, dir);
}
