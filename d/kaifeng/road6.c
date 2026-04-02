// /kaifeng/road6.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
御街是橫貫開封的主要街道，也是皇上出巡的要道。街道兩邊店鋪
亭臺不斷，小販叫賣，行人來往，車馬喧譁，一派繁華，東面一座高的
鐵塔就是有名的開封鐵塔。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"jieyin",
		"south" : __DIR__"road5",
		"north" : __DIR__"xuandemen",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
