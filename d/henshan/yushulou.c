// Room: /d/henshan/yushulou.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "御書樓");
        set("long", @LONG
御書樓為南嶽廟歷代藏書之處，天子御賜，賢達樂捐，這裏早已洋
洋大觀。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"jiayingmen",
           "north"  : __DIR__"dadian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1140);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
