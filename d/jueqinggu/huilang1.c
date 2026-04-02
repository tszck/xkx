// Room: /d/jueqinggu/huilang1.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
一條典雅的迴廊，上面畫滿當代名人的書畫。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"huilang2",
		"northeast" : __DIR__"sanqingxuan",
		"north"     : __DIR__"qingshi",
		"east"      : __DIR__"huohuanshi",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]));
 	set("coor/x", -550);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

