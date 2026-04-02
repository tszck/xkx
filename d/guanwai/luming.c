// /guanwai/luming.c

inherit ROOM;

void create()
{
	set("short", "鹿鳴峯");
	set("long", @LONG
龍門峯西側就是鹿鳴峯。鹿鳴峯又稱芝盤峯，因峯上有一草甸子，
形圓如蓋，有熱氣從地下冒出，每到嚴冬，其它峯均積雪甚厚，唯鹿鳴
峯依然植物茂盛，且盛產芝草，鹿多居之。常有鶴、雀、雕、燕飛落其
上，有“鹿鳴翠谷，雕飛芝蓋”之稱。
LONG );
	set("exits", ([
		"south"   : __DIR__"baiyun",
		"east"    : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/buck" : 1,
		__DIR__"npc/doe" : 1,
		__DIR__"npc/diao" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6180);
	set("coor/y", 5180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}