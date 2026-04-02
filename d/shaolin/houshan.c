// Room: /d/shaolin/houshan.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
你站在最中間的土屋前。土屋似乎是用本地的山嶺土夯築的，
結實而且耐水。屋頂是茅草鋪的，角上露出幾個被風吹開的破洞。
左邊的屋子好象是間豬舍，右邊的土屋門邊掛着幾串曬乾的辣椒。
正中間土屋的門是開着的。
LONG );
	set("exits", ([
		"east" : __DIR__"xiaojing2",
		"north" : __DIR__"xiaowu",
		"northeast" : __DIR__"chufang2",
		"northwest" : __DIR__"zhushe",
	]));
	set("outdoors", "shaolin");
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 710);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}