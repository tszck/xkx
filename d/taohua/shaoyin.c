// Room: /d/taohua/shaoyin.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "少陰");
	set("long", @LONG
這裏是四象層的少陰。少陰是陽中之陰。東方對應四靈獸中的青龍，
青龍之形，尚青。以方位入五行，有一道鐵梯直通下方的東方甲乙木。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"sixiang",
		"down" : __DIR__"mu",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8530);
	set("coor/y", -4680);
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
		if (local[LT_HOUR] >= 5 && local[LT_HOUR] < 11)
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
