// /d/beijing/andao10.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地會暗道");
	set("long", @LONG
終於走出了暗道，你長長的舒了一口氣。北邊是天地會青木堂的大
廳，明亮的燈光讓人感到無比溫暖。
LONG );
	set("exits", ([
		"west"  : __DIR__"andao9",
		"east"  : __DIR__"andao9",
		"north" : __DIR__"dating",
		"south" : __DIR__"andao9",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/first" : 1,
	]));
	set("coor/x", -230);
	set("coor/y", 4030);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
