inherit ROOM;

void create()
{
	set("short", "地安門西大街");
	set("long", @LONG
這是一條東西走向的大道。東邊通往地安門。西邊通往西四北大街。
南邊是西廠了，一般人都不敢往那兒去。
LONG );
        set("outdoors", "beijing");

	set("exits", ([
		"east"  : __DIR__"di_an3",
		"west"  : __DIR__"xisi2",
		"south" : __DIR__"xichangdamen",
		"north" : __DIR__"shuyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
