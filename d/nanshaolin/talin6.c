// Room: /d/nanshaolin/talin6.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "塔林");
	set("long", @LONG
這裏是少林歷代僧侶的墓地，上百座墓塔式樣繁多，造型各異。你
置身其中，只看得眼花繚亂，不知該往哪個方向走，你似乎迷路了。
LONG );
	set("exits", ([
		"northeast" : __DIR__"talin7",
		"southeast" : __DIR__"talin"+(random(10)+1),
		"northwest" : __DIR__"talin"+(random(10)+1),
		"southwest" : __DIR__"talin"+(random(10)+1),
		"south"     : __DIR__"talin"+(random(10)+1), 
		"west"      : __DIR__"talin"+(random(10)+1),
		"north"     : __DIR__"talin"+(random(10)+1),
		"east"      : __DIR__"talin5",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1780);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

