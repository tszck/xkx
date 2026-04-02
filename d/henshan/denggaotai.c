// Room: /d/henshan/denggaotai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "登高臺");
        set("long", @LONG
這裏是南天門登高望遠的好去處。你站在這裏，俯視諸峯，丘垤如
泥丸。看湘江北去，九向九背，時隱時現。周圍煙霞，碧羅，紫蓋，天
柱諸峯環抱，氣象萬千。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -1030);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
