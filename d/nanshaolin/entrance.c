// Room: /d/nanshaolin/entrance.c 木人巷入口
// Last Modified by winder on May. 29 2001

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "木人巷入口");
	set("long", @LONG
這裏是木人巷的入口。一旦走到這裏，就已經無法再回頭了，雖然
明知前面將會是步步兇險無比，也只有硬着頭皮向前闖了。
LONG );
	set("exits", ([ 
		"north" : __DIR__"murenxiang",
	]) );
	set("coor/x", 1790);
	set("coor/y", -6090);
	set("coor/z", 10);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	this_player()->delete_temp("murenxiang");
	add_action("do_save", "save");
	add_action("do_quit", "quit");
	add_action("do_quit", "exit");
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

int valid_leave(object me, string dir)
{
	if (dir == "north" && __DIR__"murenxiang"->query("busy"))
	{
		return notify_fail("有人正在闖木人巷，你先等會吧！\n");
	}
	return ::valid_leave(me, dir);
}

