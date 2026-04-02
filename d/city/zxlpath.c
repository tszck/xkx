// Room: /city/zxlpath.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "醉仙樓大堂");
	set("long", @LONG
這是醉仙樓大堂，來來往往的人客和跑堂小二，夾雜着三個宴會廳
刺耳的呼叫聲，碰杯聲，打鬧聲，賴酒聲，熱鬧非凡。你在三個宴會廳
前打量着進哪個湊個熱鬧，蹭點白食。
    每月十五日晚間比武結束，店鋪拍賣大會便在這裏舉行。屆時，萬
商雲集，直欲一試高低。如果你想發財，可不要錯過哦。
LONG);
	set("exits", ([
		"east"   : __DIR__"meigui",
		"north"  : __DIR__"furong",
		"south"  : __DIR__"mudan",
		"west"   : __DIR__"zuixianlou2",
	]));
        set("no_fight","1");
	set("no_beg", 1);
	set("coor/x", 21);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	SHOP_DIR"situheng"->come_here();
}
