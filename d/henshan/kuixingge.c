// Room: /d/henshan/kuixingge.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "奎星閣");
        set("long", @LONG
奎星閣是南嶽大廟的第二進。閣爲一個大舞臺，閣左爲鼓亭，右是
鍾亭。鄉俗年節唱戲，這裏總是熱鬧非凡。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"lingxingmen",
           "east"   : __DIR__"zhongting",
           "north"  : __DIR__"zhengchuan",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
