//tan3.c

inherit ROOM;

void create()
{
	set("short", "嘉興南湖 ");
	set("long",
		"這裏是嘉興南湖底，四周黑忽忽的，頭頂上只能看見一點亮光，身邊的水流\n"
		"似乎更加湍急了。腳下似乎有一點亮光，也不知是些什麼。周圍一片死寂，\n"
		"似乎暗藏着層層殺機。\n"

	);
	set("exits", ([
		"up" : __DIR__"tan2",
        "east" : __DIR__"tan6",
        "west" : __DIR__"tan4",
        "south" : __DIR__"tan5",
		"north" : __DIR__"tan6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
