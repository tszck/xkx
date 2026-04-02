// Room: /d/xingxiu/xxh.h
// Last Modified by winder on Apr. 25 2001

int valid_leave(object me, string dir)
{
	if ( dir == "north")
	      if(userp(me)) me->add_temp("mark/steps",1);
	if ( dir == "south")
	      if(userp(me)) me->add_temp("mark/steps",-1);
	if ( dir == "west")
	      if(userp(me)) me->add_temp("mark/step",1);
	if ( dir == "east")
	      if(userp(me)) me->add_temp("mark/step",-1);
	if (me->query_temp("mark/steps") >= 6)
	{
		me->move(__DIR__"huangdi");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		tell_room(environment(me), me->name()+"從南邊的星宿海走了過來。\n", ({ me }));
		return notify_fail("你累得半死，終於走出了星宿海。\n");
	}
	if (me->query_temp("mark/steps") <= -6)
	{
		me->move(__DIR__"xxh");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		tell_room(environment(me), me->name()+"從北邊的星宿海走了過來。\n", ({ me }));
		return notify_fail("你累得半死，終於走出了星宿海。\n");
	}
	if (me->query_temp("mark/step") <= -3)
	{
		me->move(__DIR__"xiaolu");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		tell_room(environment(me), me->name()+"從西邊的星宿海走了過來。\n", ({ me }));
		return notify_fail("你累得半死，終於走出了星宿海。\n");
	}

	if (me->query_temp("mark/step") >= 3)
	{
		me->move(__DIR__"xiaojing");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		tell_room(environment(me), me->name()+"從東邊的星宿海走了過來。\n", ({ me }));
		return notify_fail("你累得半死，終於走出了星宿海。\n");
	}
        return ::valid_leave(me,dir);
}
