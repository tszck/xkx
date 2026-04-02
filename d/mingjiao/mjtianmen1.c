// Room: /d/mingjiao/mjtianmen1.c
// Jan.5 1997 by Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天字門口");
	set("long", @LONG
前面就是明教的“天字門”了，這裏是明教中男弟子修煉的地方，
從門口看進去，汗衫揚臭，木桌流酒。此處不允女人隨意進入。
LONG );
	set("exits", ([
		"enter" : __DIR__"nanshe",
		"southeast" : __DIR__"mjtianmen",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -51110);
	set("coor/y", 710);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
 
	me = this_player();
	if ((me->query("gender")!="男性") && (dir=="enter"))
		return notify_fail("請你自重，以免不測！\n");
	else  return 1;
}