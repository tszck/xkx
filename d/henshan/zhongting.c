// Room: /d/henshan/zhongting.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "鍾亭");
        set("long", @LONG
鍾亭內設鐵鐘一口，重九千斤。每逢山洪暴發，鳴鐘鎮洪，亦以示
警，聲聞二十里外。 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"   : __DIR__"kuixingge",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -290);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
