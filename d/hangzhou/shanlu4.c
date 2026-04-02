// shanlu4.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
走在這彎彎的小路上，看着沿途山峯雲影，松竹青蔥，岩石斑駁。
不禁感到胸懷舒暢。西上便到了上天竺。東下就到了龍井。
LONG);
        set("exits", ([
            "westup"   : __DIR__"faxisi",
            "eastdown" : __DIR__"shanlu5",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
	set("coor/x", 2610);
	set("coor/y", -1600);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
