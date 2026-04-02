// Room: /d/henshan/hsroad9.c 南嶺山口
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "南嶺山口");
	set("long", @LONG
這裏是南嶺的一個山口。南面是嶺南的大鎮佛山，北面是湖南的
地界。嶺南廣東富庶繁盛，頗有豪俠之士。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northdown" : __DIR__"hsroad5",
		"southdown" : "/d/foshan/nanling",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -4000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
