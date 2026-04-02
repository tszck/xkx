// Room: /d/taohua/shaoyang.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "少陽");
	set("long", @LONG
這裏是四象層的少陽。少陽是陰中之陽。西方對應四靈獸中的白虎，
白虎之形，尚白。以方位入五行，有一道鐵梯直通下方的西方庚辛金。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"sixiang",
		"down" : __DIR__"jin",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8510);
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
		if (local[LT_HOUR] >= 17 && local[LT_HOUR] < 23)
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
