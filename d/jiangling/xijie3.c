//Edited by fandog, 02/16/2000

inherit ROOM;
void create()
{
	set("short", "西街");
	set("long", @LONG
這是荊州城西的一條南北走向的大街。似乎有不少武林中人來去匆
匆。西邊是一家書鋪，許多人進進出出，喧嚷嘈雜。東邊是知府衙門。
LONG
	);
	set("outdoors", "jiangling");
	set("objects", ([
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 1,
		"/d/taishan/npc/dao-ke" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"yamen",
		"south" : __DIR__"xijie4",
		"west"  : __DIR__"shupu",
		"north" : __DIR__"xijie2",
	]));

	set("coor/x", -1500);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}