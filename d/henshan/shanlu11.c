// Room: /d/henshan/shanlu11.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。西邊上山是赤帝峯。東邊遠遠可以看到衡山五峯之
一的紫蓋峯了。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westup"  : __DIR__"chidifeng",
           "east"    : __DIR__"shanlu12",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
