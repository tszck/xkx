// /kaifeng/road1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
這條道橫貫南北，北到宣德門，南至南盈門，是以前皇上出巡時常
走的道所以修得也是格外平整。道兩邊店鋪不斷。向南再過去不遠。經
過石拱門就是相國寺，北面是朱雀門。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"    : __DIR__"yaopu",
		"north"   : __DIR__"zhuque",
		"southup" : __DIR__"gongmen",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
