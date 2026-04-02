// Room: /d/baituo/yuanzi2.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "院子");
	set("long", @LONG
這裏堆放着上百堆的石頭。這些石頭有大有小，大如一間房屋，小如
一個鴨蛋，形狀大多都呈圓球形。你發現從有些石頭之間的縫隙(fengxi)
中飄出一股股的腥臭味，使你快要做嘔了。
LONG);
	set("exits", ([
		"southeast" : __DIR__"yuanzi1",
		"northwest" : __DIR__"yuanzi4",
		"northeast" : __DIR__"yuanzi3",
	]));
	set("item_desc", ([
		"fengxi": "\n縫隙裏面漆黑一片，隱隱約約有沙沙的聲響。\n",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -49910);
	set("coor/y", 20070);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "fengxi" )
	{
		message_vision("$N刨開縫隙口的亂石子。\n", me); 
		message("vision", me->name() + "一彎腰往縫隙裏鑽了進去。\n", environment(me), ({me}) );
		me->move(__DIR__"fengxi");
		message("vision", me->name() + "從外面鑽了進來。\n", environment(me), ({me}) );
		return 1;
	}
}
