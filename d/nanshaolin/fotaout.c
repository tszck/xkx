// Room: /d/nanshaolin/fotaout.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "古佛舍利塔");
	set("long", @LONG
這座佛塔通體飾成淡黃色，高三層，八角密檐，以溝紋大磚建造。
塔基以花崗石須彌座和三層磚雕仰覆蓮花組成，塔身正面設有一個半人
高的拱型小門。
LONG );
	set("exits", ([
		"south" : __DIR__"talin11", 
		"enter" : __DIR__"fota1",       
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

