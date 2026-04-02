inherit ROOM;

void create()
{
	set("short", "西四北大街");
	set("long", @LONG
這是一條長長的街道。東邊就是遊人們常去的文廟，那裏長年香火不斷，
煙霧繚繞。南邊是西單北大街。
LONG );
  set("outdoors", "city2");
	set("coor/x", -220);
	set("coor/y", 4070);
	set("coor/z", 0);

	set("exits", ([
		"north" : __DIR__"xisi2",
		"east" : __DIR__"wenmiao",
		"south" : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


