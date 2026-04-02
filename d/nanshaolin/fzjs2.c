// Room: /d/nanshaolin/fzjs2.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室陳設簡潔，正中一幾，一蒲團，一矮牀。北面牆上寫着大大
的一個『禪』字。一位慈眉善目的灰衣老僧正端坐於蒲團上打坐。
LONG );
	set("exits", ([
		 "south" : __DIR__"fzjs1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/tianhong" : 1,
	]));
	set("coor/x", 1780);
	set("coor/y", -6140);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("do_massage", "massage");
	add_action("do_massage", "按摩");
}
int do_massage(string arg)
{      
	object me = this_player();
	int costj, costq, times;

	if(me->query_temp("job_name")!="服侍方丈") 
		return notify_fail("搗什麼亂，把這當按摩院啊？！\n");
	if(!present("tianhong", environment(me)))
		return notify_fail("方丈不在，你搞什麼搞嘛！！\n");
	if(query("massage") > 10)
		return notify_fail("天虹方丈說道：去睡吧。明天再來服侍。\n");
	if(me->is_busy())
	{
		write("你現在正忙着呢！\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("你正在戰鬥中，無法專心幹活！\n");
		return 1;
	}
	if ( !arg || arg != "方丈" )
	{   
		message_vision("$N要給誰按摩？\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(50);
	if((int)me->query("jing")<costj || (int)me->query("qi")<costq)
	{
		message_vision("$N手忙腳亂，腳下一軟，摔倒在地。\n",me);
		me->unconcious();
		return 1;
	}
	if(!wizardp(me))
	{
		me->receive_damage("jing", costj);
		me->receive_damage("qi", costq);	
		me->start_busy(1);
	}
	if (((int)me->query_temp("mark/按摩")>times) &&
		(present("tianhong", environment(me))))
	{
		me->set_temp("mark/按摩完", 1);
		add("massage", 1);
		return notify_fail(RED "天虹方丈說道：謝謝你來服侍我，快回去休息吧(massage ok)！\n"NOR);
	}  
	message_vision("$N盤膝坐下，用力按摩方丈全身，把天虹方丈弄的爽爽的。\n", me);
	me->add_temp("mark/按摩",1);
	if ( (int)me->query_skill("buddhism", 1) < 50 && random(10)>6 )
	{
		write(HIM"你靜坐傾聽方丈誦經，對禪宗心法有些領悟。\n"NOR);
		me->improve_skill("buddhism", (me->query_skill("force",1) / 5));
	}
	return 1;
}
