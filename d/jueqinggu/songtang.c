// Room: /d/jueqinggu/songtang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "松堂");
	set("long", @LONG
面前一座三間朝東的白石敞軒，後有古樸的假山疊石。四周遍植白
皮鬆，兩側是絕壁，只見兩名綠衫僮兒手執拂塵，站在門前。
LONG
	);

	set("exits", ([
		"east"    : __DIR__"huacong11",
		"northup" : __DIR__"shanlu1",
		"westup"  : __DIR__"sanqingxuan",
		"south"   : __DIR__"qingzhiyuan",
	]));
	set("objects", ([
		__DIR__"npc/boy" : 2,
	]));

	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -360);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

