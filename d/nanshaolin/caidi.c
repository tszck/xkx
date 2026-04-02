// Room: /d/nanshaolin/caidi.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

int do_pi(string arg);

void create()
{
	set("short", "菜地");
	set("long", @LONG
一塊綠油油的菜地，種了不少蔬菜，正在茁壯成長，寺內不令肉食，
青菜就是僧人們就餐最好的食物了。菜地邊上是一個糞池，放着兩隻糞桶。
LONG );
	set("exits", ([
		"east" : __DIR__"cyzi-1",
	]) );
	set("no_fight",1);
	set("outdoors","nanshaolin");
	set("objects", ([
		CLASS_D("nanshaolin")+"/fanghui" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
	add_action("do_jiao", "澆");
}

int do_jiao(string arg)
{   
	object me = this_player();
	int costj, costq,times;

	if(me->query_temp("job_name")!="菜地種菜") 
		return notify_fail("誰讓你來的，滾！\n");
	if (me->is_busy())
	{
		write("你現在正忙着呢！\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("你正在戰鬥中，無法專心幹活！\n");
		return 1;
	}
	if ( !arg || arg != "糞" )
	{
		message_vision("$N要澆什麼？\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(50);
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N腳下一滑，掉進糞坑裏\n",me);
		me->unconcious();
		return 1;
	}
	me->start_busy(1);
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	if (((int)me->query_temp("mark/澆") > times) &&
		(present("fang hui", environment(me))))
	{
		me->set_temp("mark/澆完",1);
		message_vision(RED "方回對$N罵道：他媽的，這次就饒了你下次再教訓你，滾回去寺監那裏覆命吧(zhongcai ok)！！\n"NOR, me);
		return 1;
	}  
	message_vision("$N挑起糞桶運勁將桶中的臭糞均勻的灑於每株菜蔬的根部，真臭呀。\n", me);
	me->add_temp("mark/澆",1);
	if ( (int)me->query_skill("staff", 1) < 20 && random(10)>6 )
	{
		write(HIM"你在澆糞中對於杖的用法有些體會。\n"NOR);
		me->improve_skill("staff", (int)(me->query_skill("buddhism",1) / 5));
	}
	return 1;
}
