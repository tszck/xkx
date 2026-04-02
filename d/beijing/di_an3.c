inherit ROOM;

void create()
{
	set("short", "地安門西大街");
	set("long", @LONG
這是一條東西走向的大道。東邊通往地安門。西邊通往西四。不知
道爲什麼，這裏總是冷冷清清，見不到幾個行人。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"di_anmen",
		"west" : __DIR__"di_an4",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" :  2,
	]));
	set("coor/x", -200);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
