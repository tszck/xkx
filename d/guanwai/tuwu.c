// /guanwai/tuwu.c

inherit ROOM;

void create()
{
	set("short", "小土屋");
	set("long", @LONG
這是一座用黃土壘成的小屋，屋內打掃的很乾淨。四周的牆壁上掛
滿了各種棍子，釺子，開山斧，小鋸子等工具，看來似乎是採參所用的
工具。屋內西面的火炕上坐着一位上了年紀的老人，正在吸着旱菸袋。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaoxiang",
	]));
	set("objects", ([
		__DIR__"npc/heersu" : 1,
	]));
	set("coor/x", 6030);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}