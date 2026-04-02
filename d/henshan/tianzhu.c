// Room: /d/henshan/tianzhu.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "天柱峯");
        set("long", @LONG
你爬上衡山五峯之一的天柱峯，四望羣山縹緲雲霧中，每每天陰地
溼時候，這裏就是天柱雲氣的所在了。 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"   : __DIR__"shanlu10",
           "eastdown"   : __DIR__"shanlu7",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -1050);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
