// Room: /d/jueqinggu/qingzhiyuan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "青芝院");
	set("long", @LONG
這是一間不大的小屋，桌上，櫃中滿列藥罐，壁上一叢叢的掛著無
數乾草藥，西首並列三座丹爐，銅跡斑斑，年代久遠。
LONG
	);

	set("exits", ([
		"north" : __DIR__"songtang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

