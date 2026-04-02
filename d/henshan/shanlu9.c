// Room: /d/henshan/shanlu9.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。南邊是南臺寺，北邊通往福嚴寺。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"  : __DIR__"nantaisi",
           "northup"  : __DIR__"fuyansi",
        ]));
        set("objects", ([
            "/clone/medicine/vegetable/jinyinhua" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -330);
	set("coor/y", -1080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
