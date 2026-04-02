//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "西街");
	set("long", @LONG
這是荊州城西的一條南北走向的大街。似乎有不少武林中人來去匆
匆。北邊是城門，西邊是賣墓碑的店鋪，東邊是一家打鐵店。
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		__DIR__"npc/guofan" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"xijie2",
		"west"  : __DIR__"mubeipu",
		"north" : __DIR__"beimen",
		"east"  : __DIR__"datie",
	]));

	set("coor/x", -1500);
	set("coor/y", -1110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}