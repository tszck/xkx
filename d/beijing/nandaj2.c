// Room: /beijing/nandaj2.c

inherit ROOM;

void create()
{
	set("short", "南大街廣場");
	set("long", @LONG
這裏是一個熱鬧的廣場，正是北京城裏最熱鬧、最雜亂的地段。一
座天橋橫跨東西，正是賣雜貨、變把戲、跑江湖雜人等聚居的所在。寬
闊的大道向南北兩頭延伸。南邊是永定門，通往郊外；北邊是南大街，
通往天安門。東邊是有名的“高升茶館”，人們都愛在那兒休息聊天。
西邊有一家很大的屠宰場，不時傳來豬淒厲的哀嚎。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"tuzai",
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"yongding",
		"north" : __DIR__"nandaj1",
	]));
        set("objects", ([
		"/d/baituo/npc/snaker" : 1,
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
        ]));
	set("coor/x", -200);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
