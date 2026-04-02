#include <room.h>
inherit ROOM;

void create()
{
	set("short", "東廠兵器庫");
	set("long", @LONG
這裏是兵器庫，到處銀光閃閃，讓人眼花繚亂。寶刀、寶劍、金箍棒，
大刀、長劍、哨棒，短刀、短劍、短棍，各色各樣的兵器應有盡有，你一
時不知道挑什麼好。
LONG );

	set("exits", ([
		"north" : __DIR__"bingyin1",
		"southwest" :  __DIR__"aobai12",
	]));
	set("objects", ([
		WEAPON_DIR"changbian" : 1,
		WEAPON_DIR"changjian" : 1,
		WEAPON_DIR"gangdao" : 1,
		"/d/xingxiu/obj/tiegun" : 1,
		"/d/city/obj/duanjian" : 1,
	]));

	create_door("north", "鐵門", "south", DOOR_CLOSED);
	set("coor/x", -190);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
