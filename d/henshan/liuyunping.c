// Room: /d/henshan/liuyunping.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "流雲坪");
        set("long", @LONG
每逢雨霽，在後山深壑中升騰起來的雲山霧海，湧過南天門山脊，
向前山傾瀉，直如銀河飛瀉，蔚為壯觀，這就是南天門的流雲奇景。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1020);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
