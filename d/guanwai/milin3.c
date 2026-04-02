// /guanwai/milin3.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
這是一片茂密的松林，雜亂的生長在傾斜的山坡上。每棵松樹都有
三四抱粗細，高達十幾丈。樹冠枝多葉密，將天空完全遮住，因此林內
顯得有些昏暗。樹木之間長着很多灌木雜草，使行走很艱難，據説人蔘
就生長在這些雜草之中。
LONG );
	set("exits", ([
		"northdown"  : __DIR__"milin2",
		"eastup"     : __DIR__"heifengkou",
	]));
	set("count", 2);
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6160);
	set("coor/y", 5200);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_dig","dig");
}
int do_dig()
{
	object ob,me;
	me = this_player();

	if (query("count") < 1)
	{
		message_vision("$N滿懷希望挖了半天，別説千年人蔘了，連半年的都沒有。\n",me);
		return 1;
	}
	add("count", -1);
	message_vision("$N感到挖到個什麼東西，忙用紅線別上，輕輕掏開旁邊的細土，撿起來抹了土看看，這可是再正宗不過的長白人蔘了。\n", me);
	ob = new("/clone/medicine/vegetable/renshen");
	ob->move(me);
	return 1;
}