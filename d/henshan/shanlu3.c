// Room: /d/henshan/shanlu3.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"    : __DIR__"chidifeng",
           "northwest"  : __DIR__"shanlu4",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1070);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
 
