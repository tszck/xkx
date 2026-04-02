//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "客店二樓");
	set("long", @LONG
這是一間很大的客房，陳設十分簡陋。靠牆放了十幾張小木牀，不
少客人正和衣而臥，滿屋子都是呼呼的打酣聲。西邊有張牀是空的，你
躡手躡腳地走了過去。
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	set("coor/x", -1490);
	set("coor/y", -2120);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}