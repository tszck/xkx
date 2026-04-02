// Room: /d/henshan/jiayingmen.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "嘉應門");
        set("long", @LONG
這裏是地方官迎接京師御史官來祭南嶽的地方，是南嶽大廟第五進
門了。門上雕塑也較精細些，懸彩燈籠時時換新。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"yubeiting",
           "north"  : __DIR__"yushulou",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1150);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
