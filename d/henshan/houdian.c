// Room: /d/henshan/houdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "後殿");
        set("long", @LONG
後殿是南嶽大廟的第八進，也是南嶽大帝的寢宮。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"dadian",
           "north"  : __DIR__"beimen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1120);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
