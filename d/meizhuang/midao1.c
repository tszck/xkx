// /d/meizhuang/midao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
這是一條昏暗潮濕的地道，地道大概兩丈長，盡頭處是一扇石門。
牆壁上點着一盞油燈，發出淡黃色光芒。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"up"        : __DIR__"neishi",
		"southdown" : __DIR__"shimen",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1410);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
