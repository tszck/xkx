// /d/meizhuang/midao3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
地道一路向下傾斜，地勢不斷的向下傾斜，只怕已深入地底百丈有
餘，現在大概已經在西湖底下了。牆壁上點着一盞油燈，發出淡黃色光
芒。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"midao2",
		"southdown" : __DIR__"midao4",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1440);
	set("coor/z", -100);
	setup();
	replace_program(ROOM);
}
