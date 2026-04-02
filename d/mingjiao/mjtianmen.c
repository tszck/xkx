// Room: /d/mingjiao/mjtianmen.c
// Jan.5 1997 By Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "黃土地");
	set("long", @LONG
這是一片黃土地，塵沙泛起，劍芒凌空，刀槍晃日，殺氣盈野，幾
個小夥子膀大腰圓，一身短打，練功不輟。到此地，便能感覺到明教百
年興旺的根柢非虛。
LONG );
	set("exits", ([
		"northwest" : __DIR__"mjtianmen1",
		"southeast" : __DIR__"mjsimen1",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren": 5,
	]));
	set("outdoors", "mingjiao");
	set("coor/x", -51100);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}