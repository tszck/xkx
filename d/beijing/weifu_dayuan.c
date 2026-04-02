// /beijing/weifu_dayuan.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "韋府大院");
	set("long", @LONG
這是鹿鼎公府正廳前面一個寬闊的大院，大院裏種植着各類花草，
假山水池，瓊樓高臺，非常豪華。院內打掃得非常乾淨，韋府裏的下人
穿梭其中，北邊是一條木製走廊，通往康府的大廳。
LONG );
	set("exits", ([
		"south" : __DIR__"weifu_zoulang1",
		"north" : __DIR__"weifu_zoulang2",
	]));
	set("objects", ([
		__DIR__"npc/yuanding" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
