//room: qinyun.c

inherit ROOM;

void create()
{
	set("short","琴韻小築");
	set("long",@LONG
這是一間小巧玲瓏的房舍，頗為精雅。周圍稀稀落落的四五間小房
屋，建造在一個不知是小島還是半島上。這裏是慕容世家丫鬟阿碧的住
所。
LONG );
	set("exits",([
		"westdown" : __DIR__"muti",
		"east"     : __DIR__"xiaoting",
		"south"    : __DIR__"neitang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1500);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}