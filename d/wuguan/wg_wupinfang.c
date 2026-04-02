// wg_wupinfang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "物品房");
	set("long", @LONG
這是物品房，一個大架子。上面放的整整齊齊，看來這裏的管家是
很認真負責的，一些人正在跟管物品工具的管家說着什麼。
LONG);
	set("exits", ([
		"west" : __DIR__"wg_lang4",
		"east" : __DIR__"wg_lang6",
		"north" : __DIR__"wg_shilu-1",
	]));
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/wg_laoli" : 1,
		__DIR__"npc/wg_tlsdizi" : 1,
	]));
	set("coor/x", 41);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

