// /kaifeng/road2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
這條橫貫南北的街道是皇上出巡時的要道，北起宣德門南至南盈門，
兩邊店鋪不斷。街道東面是有名的稻香居。
LONG);
	set("no_clean_up", 0);
	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"zhuque",
		"west"  : __DIR__"gongyuan3",
		"east"  : __DIR__"daoxiang1",
	]));

	setup();
	replace_program(ROOM);
}
