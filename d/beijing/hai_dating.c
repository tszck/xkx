// /beijing/hai_dating.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府大廳");
	set("long", @LONG
這是海澄公府的大廳，大廳不大，裝飾也不華麗，很難想象這裏竟
然是一等公爵的居所。此時大廳內外一片嘈雜，擠滿了上門來尋事的御
前侍衞。
LONG );
	set("exits", ([
		"north" : __DIR__"hai_dayuan",
		"south" : __DIR__"hai_houyuan",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
		__DIR__"npc/feng" : 1,
		__DIR__"npc/duolong" : 1,
	]));

	set("coor/x", -230);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
