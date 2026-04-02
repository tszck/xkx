// Room: /d/baituo/yuanzi1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "院子");
	set("long", @LONG
這個院子裏雖只有幾顆小樹，卻堆放着上百堆的石頭。這些石頭有大
有小，大如一間房屋，小如一個鴨蛋。你發現旁邊矮牆下有一條深溝，下
面水花盈盈看不清有什麼東西。身後有道鐵門(tiemen)，不過已經關上了。
一股股的腥臭味飄來，使你快要做嘔了。
LONG);
	set("exits", ([
		"northwest" : __DIR__"yuanzi2",
		"down"      : __DIR__"shetan",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -49900);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	add_action("do_fan", "fan");
	add_action("do_fan", "pa");
	add_action("do_fan", "climb");
	add_action("do_push", "push");
	add_action("do_push", "tui");
	add_action("do_push", "strike");
}

int do_fan(string arg)
{
	int dex;
	object me;

	dex = this_player()->query_dex();
	me = this_player();
	if (dex < 18 )
		return notify_fail("這矮牆雖矮，你卻怎麼也翻不過去。\n");
	if (dex > 17 )
	{
		message_vision("$N雙手在矮牆上一按，一翻身便縱了過去。\n", me);
		me->move(__DIR__"yuanzi");
		message("vision", me->name() + "從院子裏面翻了過來。\n", environment(me), ({me}) );
		return 1;
	}
}

int do_push(string arg)
{
	int str;
	object me;
	str = this_player()->query_str();
	me = this_player();
	if( !arg ) return 0;
	if (arg == "tiemen" )
	{
		if( (int)me->query_skill("hamagong", 1))
		{
			message_vision("$N蹲下身子，雙掌平伸推向鐵門。\n", me);
			message_vision("鐵門突然打開，$N一沒留神滾了進去。鐵門卻又合上了。\n", me);
			me->add("neili", -100);
			me->receive_damage("qi", 50);
			me->move(__DIR__"yuanzi");
			return 1;
		}
		if (str < 21 )
			return notify_fail("你使出了喫奶的力氣，可就是推不動這鐵門。\n");
		if (str > 20)
		{
			message_vision("$N使出全身力氣推向鐵門，可鐵門卻紋絲不動。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
	}
	return 1;	
}
