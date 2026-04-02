// Room: /d/baituo/midao4.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIR"祕道"NOR);
	set("long", @LONG
這條陰暗的祕道在山腹中曲折延伸，不知通往何處。這裏的石壁非
常潮溼，看來附近有水源。
LONG);		
	set("exits", ([
		"westdown" : __FILE__,
		"north"    : __DIR__"midao3",
		"south"    : __DIR__"midao3",
		"eastup"   : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -49950);
	set("coor/y", 20080);
	set("coor/z", -10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <10 && me->query_con() < 30)
	{ 
		tell_object(me, HIB"你忽然感到呼吸一緊，原來是這裏的空氣污濁、流通不暢。\n" NOR );
		tell_room(environment(me),me->name()+"突然臉色變得極爲難看，並深深地吸了口氣。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}

int valid_leave(object me, string dir)
{
	if ( dir == "north") me->add_temp("mark/steps",1);
	if ( dir == "westdown") me->add_temp("mark/step",1);
	if ( dir == "south") me->add_temp("mark/steps",-1);
	if ( dir == "eastup") me->add_temp("mark/step",-1);
	if ((me->query_temp("mark/steps") == 3) &&
		(me->query_temp("mark/step") ==4))
	{
		me->move(__DIR__"tianjing");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("你正走着，突然發現前面好象有了一些光亮。\n");
	}
	if ((me->query_temp("mark/steps") == -3) &&
		(me->query_temp("mark/step") ==-4))
	{
		me->move(__DIR__"midao2");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("你正走着，突然發現前面的道路有些變化。\n");
	}
	if ((me->query_temp("mark/steps") == 10) ||
		(me->query_temp("mark/step") == 10) ||
		(me->query_temp("mark/steps") == -10) ||
		(me->query_temp("mark/step") == -10))
	{
		me->move(__DIR__"midao7");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("你正走着，突然發現前面的道路有些變化。\n");
	}
	return ::valid_leave(me,dir);
}
