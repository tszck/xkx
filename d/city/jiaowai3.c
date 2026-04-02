// Room: /d/city/jiaowai3.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
揚州郊外的樹林，松枝挺拔，喬木橫斜。林間小道，逶迤隨遠。林
中蟬鳴廝鬧，鳥啼宛轉，使你頓時煩意盡消。
    地上落了很多樹枝石塊。
LONG );
	set("exits", ([
		"north" : __DIR__"jiaowai2",
		"south" : __DIR__"jiaowai4",
	]));
	set("objects", ([
		__DIR__"obj/shitou": 2,
		"/clone/medicine/vegetable/chantui" : random(2),
	]));
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}