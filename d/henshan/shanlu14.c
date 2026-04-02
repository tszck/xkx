// Room: /d/henshan/shanlu14.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峯錯落，林壑幽深，溪泉飛瀑，雲霧繚
繞，不覺心胸大快。山路轉過芙蓉峯，西面遠遠看到藏經閣，東南方向
通往南天門。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"       : __DIR__"cangjingdian",
           "southeast"  : __DIR__"nantian",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/chuanbei" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -330);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
