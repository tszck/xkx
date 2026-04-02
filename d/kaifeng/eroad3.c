// /kaifeng/eroad3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "東大街");
	set("long", @LONG
東大街是開封府內東街區的主要通道。道路的兩端店鋪府第不斷。
行人如縷，觀光的，作生意的，攀交情的，以至走親訪友的，南邊不遠
就是山陝甘會館。西面是開封鐵塔。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"eroad2",
		"west" : __DIR__"tieta",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
