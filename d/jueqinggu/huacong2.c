// Room: /d/jueqinggu/huacong2.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "花叢");
	set("long", @LONG
這裏是一片花叢，你感到已經很難辨清道路了。
LONG
	);

	set("exits", ([
		"south"     : __DIR__"huacong"+(random(10)+1),
		"north"     : __DIR__"huacong1",
		"west"      : __DIR__"huacong"+(random(10)+1),
		"east"      : __DIR__"huacong"+(random(10)+1),
		"northeast" : __DIR__"huacong3",
		"southwest" : __DIR__"huacong"+(random(10)+1),
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -500);
	set("coor/y", -380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 
