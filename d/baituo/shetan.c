// Room: /d/baituo/shetan.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", BLU"蛇潭"NOR);
	set("long", @LONG
一個陰深深的水潭，水面離地有丈高。你感覺到水裏有東西在向你遊
來。。。是蟒蛇！快跑(jumpup)吧！
LONG);
	set("objects", ([
		    __DIR__"npc/jumang" : 2
	]));
	set("outdoors", "baituo");
	set("coor/x", -49900);
	set("coor/y", 20060);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	object ob;       
	if (interactive(ob = this_player()))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}       
	add_action("do_jumpup", "jumpup");
}

int do_jumpup(string arg)
{
 object me;
	me = this_player();
	if(me->query("qi") < 100 ) 
		return notify_fail("你已經沒有氣力跳上去了。\n");

	if (objectp(present("ju mang", environment(me))))
	{
		if( me->query_dex() > 20 && me->query_dex() < 26)
		{
			message_vision( HIR"$N用力往上一縱，卻又被巨蟒纏住了雙足落了下來！\n"NOR, me);
			me->receive_damage("qi", 150);
			me->receive_wound("qi", 50);
			return 1;
		}
		if(me->query_dex() >= 26 && me->query_dex() < 32)
		{
			message_vision( HIY"$N用力往上一縱，雖差點又被巨蟒纏住了雙足，但終於逃出了蛇潭！\n"NOR, me);
			me->receive_damage("qi", 150);
			me->receive_wound("qi", 50);
			me->move(__DIR__"yuanzi1");
			tell_room(environment(me),me->name()+"從蛇潭之中爬上來，腳下一軟，臉色蒼白地坐倒在地。\n", ({ me }));
			return 1;
		}
		if(me->query_dex() >= 32)
		{
			message_vision(HIR"$N用力往上一縱，跳出了蛇潭。\n"NOR, me);
			me->receive_damage("qi", 50);
			me->receive_wound("qi", 10);
			me->move(__DIR__"yuanzi1");
			tell_room(environment(me),me->name()+"從蛇潭之中跳了上來，模樣狼狽不堪。\n", ({ me }));
			return 1;
		}
		else
		{ 
			message_vision("$N使勁一跳，可是跳不上去。\n", me);
			return 1;
		}
	}
	else
	{ 
		message_vision("$N使勁一縱，跳出了蛇潭。\n", me);
		me->receive_damage("qi", 50);
		me->move(__DIR__"yuanzi1");
		tell_room(environment(me),me->name()+"突然從蛇潭之中跳了出來，臉帶恐懼之色。\n",({ me }));
		return 1;
	}
}

int greeting(object ob)
{
	object me = this_player();	
	if( (int)me->query_temp("baituo_climb") )
	{
		message_vision(HIR"$N從牆上跳了下來，正好落在了巨蟒身上！。\n"NOR,me);
		message_vision(HIR"$N還沒回過神來，已經被巨蟒纏住了！\n"NOR,me);
		write(BLU"你被巨蟒纏住，越來越緊。。。\n你感到一切事物都開始慢慢遠離你而去了。。。\n"NOR);
		me->delete_temp("baituo_climb");
		me->unconcious();
		return 1;
	}
	if((int)me->query_temp("baituo_climb1") )
	{
		message_vision(HIR"$N從牆上跳了下來，正好落在了巨蟒身旁！。\n"NOR,me);
		message_vision(HIR"$N猛力一跳，雙腳卻還是被巨蟒纏住！\n"NOR,me);
		write(BLU"你被巨蟒纏住，越來越緊。。。再不想法逃跑就死定了！\n"NOR);
		me->receive_damage("qi", 500);
		me->receive_wound("qi", 200);
		me->delete_temp("baituo_climb1");
		return 1;
	}
	if( (int)me->query_temp("baituo_climb2") )
	{
		message_vision(HIR"$N剛剛飛縱過來，就發現了蛇潭裏有巨蟒！。\n"NOR,me);
		write(BLU"你看見巨蟒向你捲了過來，快走！\n"NOR);
		message_vision( HIY"$N身在半空雙臂一揮，身體借力又直飛出去，跳出了蛇潭！\n"NOR, me);
		me->add("neili", -100);
		me->move(__DIR__"yuanzi1");
		tell_room(environment(me),me->name()+"從蛇潭之中飛躍上來，臉上帶着驚訝之色。\n",({ me }));
		me->delete_temp("baituo_climb2");
		return 1;
	}      
}