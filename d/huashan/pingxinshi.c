// pingxinshi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "平心石");
	set("long", @LONG
百尺峽盡頭，兩邊巖崖勢欲相合，中夾兩塊巨石，前邊一塊刻有“
驚心石”三字。過此回望，石上刻有“平心石”三字，示人們以險境已
經過去，已進入平安之途了。頓時心情至此一舒。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"   : __DIR__"laojun",
		"westdown" : __DIR__"baichi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -880);
	set("coor/y", 230);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
