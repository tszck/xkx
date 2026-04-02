// midao3.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你的眼前是一條用漢白玉鋪成的臺階，一直向下延伸，兩邊的牆壁
都是花崗巖，牆上隔十來步就有一盞油燈，使你能看清周圍。
LONG );
	set("exits", ([
		"southup" : __DIR__"midao2",
		"eastdown": __DIR__"midao4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}