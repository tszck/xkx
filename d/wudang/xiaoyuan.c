// xiaoyuan.c 後山小院
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "後山小院");
	set("long", @LONG
這是後山的一座小院，佈置簡簡單單，除了一牀、一桌、一椅、一
蒲團，再也沒有別的什物。比較引人注目的是牆上掛着一把劍。這裏就
是武當開山祖師張三豐的練功所在。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhang" : 1 
	]));
	create_door("north", "竹門", "south", DOOR_CLOSED);
	set("coor/x", -2050);
	set("coor/y", -960);
	set("coor/z", 90);
	setup();
}