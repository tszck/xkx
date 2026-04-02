// /beijing/weifu_zoulang1.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "韋府走廊");
	set("long", @LONG
這是一條木製的走廊，地面很是光滑，被打整得一塵不染。幾個韋
府的下人在此走動。北邊是個巨大的花園。
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_dayuan",
		"south" : __DIR__"weifu_men",
	]));
	set("objects", ([
		__DIR__"npc/shizhe" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
