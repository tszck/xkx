// Room: /d/jueqinggu/shufang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "書房");
	set("long", @LONG
這是公孫止的書房，書架上放着一些武林祕籍，一般很少有人能夠
進來。
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanqingxuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -540);
	set("coor/y", -350);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

