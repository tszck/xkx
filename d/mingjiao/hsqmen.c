//HSQMEN.C

inherit ROOM;

void create()
{
	set("short", "洪水旗大門");
	set("long", @LONG
這裏是明教洪水旗的大門，莊嚴古樸，門前對插四面鑲藍蟠龍旗門
前水聲潺潺，卻是一條水流從門下流出，正是瀑布的上源。原來，整個
洪水旗就建築在這條小河之上。
LONG );
	set("exits", ([
		"enter" : __DIR__"hsqchanglang",
		"south" : __DIR__"tohsq7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 930);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}