// Room: /city/xiaobaozhai.c

inherit ROOM;

void create()
{
	set("short", "小寶齋");
	set("long", @LONG
撫遠大將軍掛官出逃後，帶了七個老婆，躲在這裏偷偷開了這個小
寶齋。賣些當年帶回來的金銀珠寶，收購一些古董倒賣，着實發了不少
橫財。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("objects", ([
		"/quest/weixiaobao" : 1,
	]));
	set("exits", ([
		"east"   : __DIR__"shilijie1",
	]));

	set("coor/x", 0);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}