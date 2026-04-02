// /kaifeng/road5.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
御街是橫貫開封的主要街道，也是皇上出巡的要道。街道兩邊店鋪
亭臺不斷，小販叫賣，行人來往，車馬喧譁，一派繁華，南邊的高橋就
是州橋，西面是龍亭寺。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"west"    : __DIR__"tingyuan",
		"north"   : __DIR__"road6",
		"southup" : __DIR__"road4",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
