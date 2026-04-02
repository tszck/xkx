// Room: /d/taohua/taiyin.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "太陰");
	set("long", @LONG
這裏是四象層的太陰。太陰是陰中之陰，也即至陰。北方對應四靈
獸中的玄武，烏龜之形，尚黑。以方位入五行，有一道鐵梯直通下方的
北方壬癸水。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"sixiang",
		"down" : __DIR__"shui",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4670);
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
		if (local[LT_HOUR] >= 23 || local[LT_HOUR] < 5)
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
