// Room: /d/henshan/banshan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "半山亭");
        set("long", @LONG
終於到了半山亭。這裏離到祝融峯無論高程還是行程，均恰好是一
半之徑，路邊小亭顯然已極古久，但仍為過往客旅遮風避雨。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu4",
           "northup"    : __DIR__"shanlu5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "henshan");
	set("coor/x", -320);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
