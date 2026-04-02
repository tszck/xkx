// Room: /d/taohua/taiji.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "太極");
	set("long", @LONG
這裏是太極層，你一走下來，往上的鐵梯就被撤掉了。往下有一道
懸掛着的鐵梯，通向兩儀層。太極是世界的統一體，陰陽流轉不息，互
相轉化，成為一個整體，這就是所謂的混沌狀態。由太極的兩個極端變
化而生出陰陽，就是太極生兩儀。
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 20);
	setup();
}

void init()
{
	object me = this_player();

	me->delete_temp("wuxing");
	me->delete_temp("liangyi");
	me->delete_temp("sixiang");
	me->delete_temp("wuxing_total");
	me->delete_temp("wuxing_step");
	me->delete_temp("wuxing_error");
	add_action("do_save", "save");
	add_action("do_quit", "quit");
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