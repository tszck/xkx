// Room: /d/henshan/nantaisi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "南臺寺");
        set("long", @LONG
南臺寺為禪宗七祖懷讓的弟子石頭希遷的道場，寺下紫雲峯上是石
頭和尚墓。寺周林蔭夾道，曲徑通幽，泉流叮咚，蜂蝶紛飛，山風吹過
時萬葉悉索，真好去處。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northdown"  : __DIR__"shanlu9",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1090);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
