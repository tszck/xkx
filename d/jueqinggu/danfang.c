// Room: /d/jueqinggu/danfang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "丹房");
	set("long", @LONG
這裏是絕情谷煉製丹藥的地方，屋裏瀰漫着一股刺鼻的藥味。
LONG
	);

	set("exits", ([
		"south" : __DIR__"huilang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -560);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

