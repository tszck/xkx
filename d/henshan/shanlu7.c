// Room: /d/henshan/shanlu7.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。山路東西通向磨鏡臺和天柱峯。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westup"    : __DIR__"tianzhu",
           "eastdown"  : __DIR__"mojingtai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
