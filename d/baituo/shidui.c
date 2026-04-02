// Room: /d/baituo/shidui.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "亂石堆");
	set("long", @LONG
這裏四周所圍全是巨石，地上鋪滿了凌亂的碎石子，象是被人擊打
巨石所打下來的碎塊。正中一塊平滑的青石板上蹲着一隻雪白的蛤蟆。
LONG);	
	set("objects", ([
		__DIR__"npc/chanchu" : 1,
	]));
	set("item_desc", ([
		"stone": "\n這些巨石都有凹面，看得出是被人拿來練掌力用的。\n",
	]));
	set("outdoors", "baituo");
	set("coor/x", -49910);
	set("coor/y", 20090);
	set("coor/z", 40);
	setup(); 
}

void init()
{
	object me = this_player();	
	if(me->query("id") != "xuanbing chanchu") 
	if(me->query_skill("xidu-poison",1) < 50) 
	{
		message_vision(HIW"玄冰蟾蜍突然縱起，對着$N一口毒氣噴出！\n"NOR,this_player()); 
		tell_object(me, HIB"你感到腦中一陣旋暈，立時昏了過去。\n" NOR );
		me->unconcious();
		me->move(__DIR__"yuanzi5");
		tell_room(environment(me),me->name()+"突然從巨石之上直落下來，‘叭’的一聲摔在地上！\n", ({ me }));
		me->add("max_neili", -1);
	}
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_strike", "strike");
}

int do_climb(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		message_vision("$N手腳並用，爬上了巨石去。\n", me);
		message_vision("$N翻身一縱，已經跳了出去。\n", me);
		me->move(__DIR__"yuanzi5");
		message("vision", me->name() + "從裏面跳了出來。\n",environment(me), ({me}) );
		return 1;
	}
}

int do_strike(string arg)
{
	object me = this_player();
	int improve, cost, lvl, exp;

	lvl = me->query_skill("strike",1);
	exp = me->query("combat_exp");
	improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		if(!me->query_skill("hamagong", 1))
			return notify_fail("你用手指推了推巨石，臉上露出一絲難堪的神色。\n");
		if(me->query_skill("hamagong", 1) > 100)
			return notify_fail("你一掌向巨石推去，只聽轟的一聲，巨石被你掌力震成兩半！\n");
		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if((int)me->query("qi") < cost || (int)me->query("jing") < cost)
		{
			message_vision("$N用力過猛, 一不留神勁力反彈，震得$N暈了過去。\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$N默誦蛤蟆功口訣，運力於雙掌之上，一掌掌向巨石推去。\n"NOR,this_player());
		if ( lvl < 100 && lvl*lvl*lvl/10 < exp)
			me->improve_skill("strike", improve/4); 
		me->improve_skill("hamagong", improve);
		me->receive_damage("jing", cost);
		me->receive_damage("qi", cost);			
		return 1;
	}
}

