//tan4.c

inherit ROOM;

void create()
{
	set("short", "嘉興南湖 ");
	set("long",
		"這裏是嘉興南湖底，四周黑忽忽的，頭頂上看不見一點亮光，身邊的水流\n"
		"忽上忽下的湧動着。看起來是一處海眼。腳下似乎有一點亮光，也不知是些\n"
		"什麼。周圍一片死寂，似乎暗藏着層層殺機。\n"

	);
	set("exits", ([
		"up"   : __DIR__"tan2",	
		"down" : __DIR__"tan5",
		"southwest" : __DIR__"tan6",
		"northwest" : __DIR__"tan6",
		
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -1010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
