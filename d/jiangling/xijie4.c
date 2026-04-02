//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "西街");
	set("long", @LONG
這是荊州城西的一條南北走向的大街。似乎有不少武林中人來去匆
匆。西邊是一座軒朗巍峨的道觀，東邊是萬家大院，南邊是高大的城門。
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/xiangnong" : random(3),
		__DIR__"npc/xiaofan" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"damen",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"kaiyuanguan",
		"north" : __DIR__"xijie3",
	]));
	set("coor/x", -1500);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
