// chuchang shi

inherit ROOM;

void create()
{
	set("short", "儲藏室");
	set("long", @LONG
這裏是丐幫的儲藏室，你現在只能看見一個個鎖着的箱子。
LONG );
	set("exits", ([
		"west" : __DIR__"mishi",
		"east" : __DIR__"undertre",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
