// Room: /city/dongmen.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "得勝山");
	set("long", @LONG
得勝山是當年嶽飛大破金兵之處，現在的山由已經長滿了密密的樹
木，一般走到這塊山腳下的空地就爬不上去了。中間空的大約是幾丈見
方，地上的草也沒有，看得出，來此的人還不少。
LONG );
	set("outdoors", "yangzhoue");
	set("exits", ([
		"west" : __DIR__"jiaowai1",
	]));

	set("no_clean_up", 0);
	set("coor/x", 75);
	set("coor/y", -20);
	set("coor/z", 3);
	setup();
	replace_program(ROOM);
}