//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "山道");
	set("long", @LONG
這是一條黃泥山道，不時可見江湖中人揹着包袱，彆着刀劍往北走
去。地上有許多車馬碾過的痕跡。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaowu",
		"north" : __DIR__"nanmen",
		"east"  : __DIR__"shandao4",
		"west"  : __DIR__"shandao2",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2053);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}