// /beijing/weifu_zoulang2.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "韋府走廊");
	set("long", @LONG
這是一條木製的走廊，地面很是光滑，被打整得一塵不染。幾個韋
府的下人在此走動。南邊是個巨大的花園，北邊就是韋府的大廳。
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_dating",
		"south" : __DIR__"weifu_dayuan",
	]));

	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
