// Room: /d/jueqinggu/huilang2.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
一條典雅的迴廊，上面畫滿當代名人的書畫。
LONG
	);

	set("exits", ([
		"south"     : __DIR__"xiufang",
		"northeast" : __DIR__"huilang1",
		"north"     : __DIR__"danfang",
	]));
	set("objects", ([
		__DIR__"npc/puren1" : 1,
	]));
 	set("coor/x", -560);
	set("coor/y", -380);
	set("coor/z", 20);
	setup();
	 
}
int valid_leave(object me, string dir)
{
	  if (!me->query("jqg_pass")&&
	  present("pu ren", environment(me)) &&
	  (dir=="north"))
	  return notify_fail("僕人攔住你說道，丹房沒經谷主同意，不能隨便進入。\n");
	  return ::valid_leave(me, dir);
}
