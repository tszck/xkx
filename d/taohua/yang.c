// Room: /d/taohua/yang.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "陽");
	set("long", @LONG
這裏是兩儀層的陽。陽是太極的一端，古人以光明為陽，以生命為
陽，又以地理而認為南方屬陽，山之南水之北為陽。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8510);
	set("coor/y", -4690);
	set("coor/z", 10);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) {
		local = localtime(time());
		if (local[LT_MDAY] > 15)
			me->set_temp("liangyi", 1);
		else
			me->set_temp("liangyi", -1);
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
