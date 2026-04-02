// gytoad1.c 果園小路
// by Java

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "果園小路");
	set("long", @LONG
眼前豁然開朗，你輕鬆地走在果園邊的小路上。路上落英繽紛，兩
邊是桃樹林，盛開着粉紅的桃花，紅雲一片，望不到邊。還可以看蜜蜂
「嗡嗡」地在花間飛上飛下忙個不停，間或傳來猿猴的嘰咋聲。
LONG );
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad13",
		"east" : __DIR__"gyroad2",
	]));
	set("objects", ([
		__DIR__"npc/jumang": 1
	]));
	set("coor/x", -1930);
	set("coor/y", -930);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "east" && objectp(present("ju man", environment(me))))
		return notify_fail(RED"朱冠巨蟒"NOR"一躍攔住你的去路。\n");

	return ::valid_leave(me, dir);
}
