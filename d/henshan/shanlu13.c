// Room: /d/henshan/shanlu13.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。東北方就是南天門了，高高矗立在西北方的就是衡
山五峯之一的芙蓉峯。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northeast"  : __DIR__"nantian",
           "southeast"  : __DIR__"shanlu5",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1030);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
