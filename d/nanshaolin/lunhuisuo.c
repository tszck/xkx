// Room: /d/nanshaolin/lhsuo.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIG"輪迴所"NOR);
	set("long", @LONG
你一腳蹬開門看時，發現這裏原來就是南少林寺的大東廁。裏面穢
氣畜人，正是五穀輪迴之所。不過少林和尚十分勤快，氣味雖重，地面
倒是打掃得非常乾淨。
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu2",
        ]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/fangyan" : 1,
        ]));
	set("coor/x", 1830);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

