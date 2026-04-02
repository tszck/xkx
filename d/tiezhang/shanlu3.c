// Room: /d/tiezhang/shanlu3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一條崎嶇的山路上，道旁山峯壁立，長草過腰，中間一條羊
腸小路，僅容一人勉強過去。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"south"   : __DIR__"hhyuan1",
		"northup" : __DIR__"shanlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1930);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}