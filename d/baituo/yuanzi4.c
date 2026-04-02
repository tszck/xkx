// Room: /d/baituo/yuanzi4.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "院子");
	set("long", @LONG
這裏堆放着上百堆的石頭。這些石頭有大有小，大如一間房屋，小如
一個鴨蛋，形狀大多都呈圓柱形。你發現從有些石頭之間的縫隙(fengxi)
中飄出一股股的腥臭味，使你快要做嘔了。
LONG);
	set("exits", ([
		"southeast" : __DIR__"yuanzi2",
		"northeast" : __DIR__"yuanzi5",
		"east"      : __DIR__"yuanzi3",
	]));
	set("item_desc", ([
		"fengxi": "\n縫隙裏面漆黑一片，隱隱約約有沙沙的聲響。\n",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -49920);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	if(me->query_temp("baituo_stone2"))
	{
		me->delete_temp("baituo_stone2");
		me->set_temp("baituo_wait", 1);
		remove_call_out("do_open");
		call_out("do_open", 30, me);
	}
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
		message_vision("$N刨開縫隙口的亂石子。\n" NOR, me); 
		message("vision", me->name() + "一彎腰往縫隙裏鑽了進去。\n", environment(me), ({me}) );
		me->move(__DIR__"fengxi2");
		message("vision", me->name() + "從外面鑽了進來。\n", environment(me), ({me}) );
		return 1;
	}
}

void do_wait()
{
	object me = this_player();
	if(environment(me) && me->query_temp("baituo_wait"))
	{
		remove_call_out("do_open");
		call_out("do_open", 1, me);
	}
}

int do_open()
{
 
	object room;	
	message("vision","石柱忽然發出軋軋的聲音，向一側緩緩移開，向下露出一個黑洞洞的入口。\n", this_object() );
	set("exits/down", __DIR__"midao0");
	if( room = load_object(__DIR__"midao0") )
	{
		 room->set("exits/up", __FILE__);
		 message("vision",
 "頭頂上的石柱忽然發出軋軋的聲音，露出一個光亮亮的洞口。\n",room );
	} 
	remove_call_out("close_door");
	call_out("close_door", 3);
	return 1;
}

void close_door()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision","石柱發出軋軋的聲音，緩緩地移回原處，將向下的洞口蓋住了。\n", this_object() );
	if( room = load_object(__DIR__"midao0") )
	{
		room->delete("exits/up");
		message("vision","頭頂上發出軋軋的聲音，石柱又緩緩地收了回去，階梯消失了。\n", room );
	}
	delete("exits/down");
}

int valid_leave(object me, string dir)
{	
	me->delete_temp("baituo_wait");
	return ::valid_leave(me, dir);
}