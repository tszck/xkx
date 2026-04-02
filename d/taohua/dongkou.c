// Room: /d/taohua/dongkou.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
在桃花叢里居然安排了這麼一個巖洞，可見島主用心之巧。巖洞周
圍全是桃花，而向洞裏看，黑乎乎地什麼也看不見。
LONG
	);
	set("exits", ([ 
		"west"  : __DIR__"road3",
		"enter" : __DIR__"cave",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 9200);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}