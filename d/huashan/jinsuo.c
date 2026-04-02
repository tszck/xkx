// jinsuo.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "金鎖關");
	set("long", @LONG
金鎖關山勢形如一把鎖，下面是一片開闊地，兩旁是高聳入雲的峭
壁，中間一條羊腸小道。真是一夫當關，萬夫莫開。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"zhenyue",
		"northdown" : __DIR__"shangtianti",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
