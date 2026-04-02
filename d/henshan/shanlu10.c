// Room: /d/henshan/shanlu10.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。山路向西通向方廣寺。東面是天柱峯。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastup"    : __DIR__"tianzhu",
           "westdown"  : __DIR__"fangguangsi",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/chaihu" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -360);
	set("coor/y", -1050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
