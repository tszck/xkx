// Room: /d/jueqinggu/xiufang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "繡房");
	set("long", @LONG
這裏是公孫綠萼的繡房，整個房間秀雅整潔，一個少女正坐在窗前
沉思。
LONG
	);

	set("exits", ([
		"north" : __DIR__"huilang2",
	]));
	set("objects", ([
		__DIR__"npc/gongsunlve" : 1,
	]));
	set("coor/x", -560);
	set("coor/y", -390);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
 
