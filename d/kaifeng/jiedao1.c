// /kaifeng/jiedao1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
這條道橫貫南北，北到宣德門，南至南盈門，是以前皇上出巡時常
走的道，所以修得是格外平整。道兩邊店鋪不斷。西面就是開封府的大
堂，再向南一點就可以出城了。
LONG);
	set("outdoors", "kaifeng");
	set("exits", ([
		"west" : __DIR__"kaifeng",
		"north" : __DIR__"jiedao",
		"south" : __DIR__"jiedao2",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
