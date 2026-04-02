//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "山道");
	set("long", @LONG
這是一條黃泥山道，不時可見江湖中人揹着包袱，彆着刀劍走來走
去。地上有許多車馬碾過的痕跡。東邊是一片亂葬岡子。
LONG );
	set("exits", ([
		"east"  : __DIR__"shangang1",
		"west"  : __DIR__"shandao4",
		"north" : __DIR__"dongmen",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}