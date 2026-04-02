// Room: /d/henshan/shiziyan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "獅子巖");
        set("long", @LONG
獅子巖佈滿奇形怪狀的岩石，細究則絕類獅子，騰躍伏吼，各肖其
類。到獅子巖，祝融峯已經在望了。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southwest"  : __DIR__"nantian",
           "northup"    : __DIR__"wangritai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
