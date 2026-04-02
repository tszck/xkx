#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"天井"NOR);
	set("long", @LONG
轉過一道石壁，你的眼前忽然一亮。原來這裏是個天然形成的天井，
大約幾十來丈見方，頭頂一個圓洞，光亮都是從那裏照射進來的。一條
暗流從山腹流過這裏，旁邊長慢了各種花草，還有幾顆果樹。隨着一聲
鶴鳴，你發現有一隻罕見的丹頂鶴正站在溪邊看着你。
LONG);
	set("resource/water", 1);
	set("objects", ([
		__DIR__"npc/he" : 1,
		"/clone/book/bt_book4" : 1
	]));	
	set("exits", ([
		"out" : __DIR__"midao4",
	]));
	set("outdoors", "baituo");
	set("grass_count",8);
	set("guo_count",10);
	set("coor/x", -49950);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	this_player()->set_temp("find_times", 20);
	add_action("do_find", "find");
	add_action("do_zhai", "zhai");
}

int do_find()
{
	object me, ob;
	int luck;
	me = this_player();
	ob = new(__DIR__"obj/grass");
	luck = (int)me->query_int() * (int)me->query_con() / 5;
	luck = luck + (int)me->query("kar") / 3 - 30;
	message_vision("$N蹲下身子，在草叢中仔細地尋找着什麼。\n", me);
	if ( me->query_temp("find_times") == 0 )
	{
		message_vision("$N一不小心被雜草割了一個傷口，鮮血直流！\n",me);
		me->set_temp("find_times", random(20));
		me->receive_wound("qi", 65);
		return 1;
	}
	me->add_temp("find_times", -1);
	if (random(luck) > 115 && query("grass_count") >= 1)
	{
		add("grass_count", -1);
		ob->move(me);
		message_vision("$N“咦”了一聲，原來發現了一株斷腸草。\n", me);
	}
	return 1;
}

int do_zhai(string arg)
{
	object me = this_player();
	if (arg == "guo" && me->query_dex() > 25 && query("grass_count") >= 1)
	{
		message_vision("$N順手從果樹上摘下一個果子。\n", me);
		new(__DIR__"obj/guo")->move(me);
		add("grass_count", -1);
		return 1;
	}
	return notify_fail("你要摘什麼？\n");
}
