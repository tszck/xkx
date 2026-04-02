// /beijing/hai_men.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府門");
	set("long", @LONG
這是一所巨宅，巨宅的大門緊緊關閉着，門上掛着一塊大匾，匾上
寫着“海澄公府”四個大字，雖然和鹿鼎公府同是公爵府，可是大小、
派頭卻大不相同，大門匾額上那“海澄公府”四字是黑字，一點也不起
眼。
LONG );
	set("exits", ([
		"east"  : __DIR__"xidan1",
		"south" : __DIR__"hai_dayuan",
	]));

	set("no_clean_up", 0);
	set("coor/x", -230);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
