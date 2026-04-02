// Room: /d/jueqinggu/qingshi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "寢室");
	set("long", @LONG
這是公孫止的睡房，裏面的牀上綾羅綢緞，牀邊站着一名丫鬟，窗
戶半開，屋內光線不太明亮。
LONG
	);

	set("exits", ([
		"south" : __DIR__"huilang1",
	]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -550);
	set("coor/y", -360);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

