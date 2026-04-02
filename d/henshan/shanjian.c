// Room: /d/henshan/shanjian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山澗");
        set("long", @LONG
順山澗漂流而下，沿溪遍佈珍稀樹木，泉石，林木，花草及峯巒均
極宜人。澗流至崖摺疊飛泄而下，聲震山谷。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "down"     : __DIR__"heishatan",
           "northup"  : __DIR__"fangguangsi",
        ]));
        set("outdoors", "henshan");
        set("objects", ([
                "/clone/medicine/vegetable/gouzhizi" : random(2),
        ]));
	set("coor/x", -370);
	set("coor/y", -1060);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
