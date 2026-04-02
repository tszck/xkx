// /beijing/hai_dayuan.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府大院");
	set("long", @LONG
這是進門後的一個不大的花園。西面是一個廂房，東面是一扇月形
門通往海澄公府的花廳，北面是海澄公府的大門，南面就是大廳了。
LONG );
	set("exits", ([
		"north" : __DIR__"hai_men",
		"south" : __DIR__"hai_dating",
		"east" : __DIR__"hai_huating",
		"west" : __DIR__"hai_fang",
	]));
	set("objects", ([
		__DIR__"npc/shiwei1" : 1,
		__DIR__"npc/shiwei2" : 1,
	]));

	set("outdoors", "beijing");
	set("coor/x", -230);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
