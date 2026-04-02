// baichi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "百尺峽");
	set("long", @LONG
走過千尺幢，前面又見另一要命的百尺峽，百尺峽不似千尺幢般險
峻，但亦十分陡峭，巖壁兩側設有鐵索以作扶攔。百尺峽又稱百丈崖，
是一座壁立千仞的懸崖。崖底到上面的最低的埡口處約百尺，故有是名。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"    : __DIR__"pingxinshi",
		"northdown" : __DIR__"qianchi",
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 230);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
 
