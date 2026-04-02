// Room: /d/foshan/nanling.c 南嶺山口
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "南嶺山口");
	set("long", @LONG
這裏是南嶺的一個山口。南面就是佛山了，北面是橫亙湖南廣
東的五嶺。這裏地氣炎熱，百物速生快長，口音也遠異中原了。
LONG );
	set("outdoors", "foshan");
	set("exits", ([
		"northup" : "/d/henshan/hsroad9",
		"south"   : __DIR__"northgate",
	]));
        set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", 5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
