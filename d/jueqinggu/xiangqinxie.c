// Room: /d/jueqinggu/xiangqinxie.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "響琴榭");
	set("long", @LONG
響琴榭分為三間，東南北三面為敞選，中為明間，頂部平直，結構
靈巧。榭下是引泉入池的渠道，上有響琴橋，流水擊石，聲若琴瑟。氣
爽風清，是讀書做畫之地。
LONG
	);

	set("exits", ([
		"westdown"  : __DIR__"feiyunyan",
		"southdown" : __DIR__"guanlanting",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -480);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

