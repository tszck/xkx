// /kaifeng/jiedao2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
這條道橫貫南北，北到宣德門，南至南盈門，是以前皇上出巡時常
走的道，所以修得是格外平整。街道兩邊的店鋪不斷。北邊過去不遠，
就是大相國寺。東面是繁塔。
LONG);
	set("outdoors", "kaifeng");
	set("exits", ([
		"east":__DIR__"fanta",
		"north" : __DIR__"jiedao1",
		"south" : __DIR__"nanying",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
