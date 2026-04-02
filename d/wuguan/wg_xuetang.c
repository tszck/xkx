// wg_xutang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "學堂");
	set("long", @LONG
這裏是武館內的一個小學堂，堂內陣陣朗朗讀書聲，一個先生在這
裏認真的教着，這裏放滿了桌子和椅子。
LONG);
	set("exits", ([
		"west" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_fang" : 1,
		__DIR__"npc/wg_hengshandizi" : 1,		
	]) );
	set("coor/x", 51);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


