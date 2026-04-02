// Room: /d/lingxiao/muwu.c
// Last Modified by Winder on Jul. 15 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "木屋");
	set("long", @LONG
這是凌霄城弟子在城外巡邏護山的哨所，每天都有雪山弟子守衛，
以保護凌霄城安全清淨。不過，憑凌霄城在武林中的名頭，一般宵小之
輩也不敢來此搗亂。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"sroad6",
	]));
	create_door("west", "木門", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
} 

