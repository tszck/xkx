inherit ROOM;

void create()
{
	set("short", "地安門東大街");
	set("long", @LONG
這是一條東西走向的大道。西邊通往地安門。東邊通往王府井。
LONG );
        set("outdoors", "beijing");

	set("exits", ([
		"east" : __DIR__"di_an1",
		"west" : __DIR__"di_anmen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg" :  2,
	]));
	set("coor/x", -180);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
