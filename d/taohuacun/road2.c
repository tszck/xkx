// /d/taohuacun/road2.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set("short","田間小路");
	set("long", @LONG
這是鄉下田間南北走向的一條小路，彎彎曲曲的伸向前方。路的兩
邊是以前鄉民們種菜的地方。
LONG
);
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"road1",
		"east"  : __DIR__"caidi4",
		"west"  : __DIR__"caidi3",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}