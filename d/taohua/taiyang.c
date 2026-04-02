// Room: /d/taohua/taiyang.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "太陽");
	set("long", @LONG
這裏是四象層的太陽。太陽是陽中之陽，也即至陽。南方對應四靈
獸中的朱雀，赤日之形，尚紅。以方位入五行，有一道鐵梯直通下方的
南方丙丁火。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"sixiang",
		"down" : __DIR__"huo",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4690);
	set("coor/z", 0);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("sixiang")) {
		local = localtime(time());
		if (local[LT_HOUR] >= 11 && local[LT_HOUR] < 17)
			me->set_temp("sixiang", 1);
		else
			me->set_temp("sixiang", -1);
	}
}

int do_save()
{
	write("這裏不準存盤！\n");
	return 1;
}

int do_quit()
{
	write("這裏不準退出！\n");
	return 1;
}
