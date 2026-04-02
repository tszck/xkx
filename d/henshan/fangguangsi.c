// Room: /d/henshan/fangguangsi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "方廣寺");
        set("long", @LONG
方廣寺在蓮花峯下。蓮花峯有八個山頭，猶如金蓮瓣瓣，方廣寺就
建在這蓮花中心的一片平地上。深邃幽雅，有 "不遊方廣寺，不知南嶽
之深" 之説，故 "方廣寺之深" 為衡山大四絕之一。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanjian",
           "eastup"     : __DIR__"shanlu10",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
