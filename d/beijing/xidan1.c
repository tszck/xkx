inherit ROOM;

void create()
{
	set("short", "西單北大街");
	set("long", @LONG
這裏是西單北大街。東邊有一家很大的賭場，裏面鬧哄哄的。北邊
是西四北大街。南邊就是西單了。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"north" : __DIR__"xisi",
		"south" : __DIR__"xidan",
		"east"  : __DIR__"duchang",
		"west"  : __DIR__"hai_men",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
