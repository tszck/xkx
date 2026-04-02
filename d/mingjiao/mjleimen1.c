// Room: /d/mingjiao/mjleimen1.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "雷字門口");
	set("long", @LONG
前面就是明教的“雷字門”了，這裏是明教中西域弟子修煉的地方。
西域風俗大異中土，他們的生活習慣以及使用物品也與中土迥異。
LONG );
	set("exits", ([
		"enter" : __DIR__"sushe",
		"northeast" : __DIR__"mjleimen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -51110);
	set("coor/y", 490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}