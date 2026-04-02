// wg_mafang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "馬房");
	set("long", @LONG
這裏是馬房，裏面臭烘烘的，養了幾十匹馬，你看過去，馬身上都
很髒了，該洗洗了，旁邊有個水池，裏面有些清水。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_houyuan2",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia3" : 1,
	]));
	setup();
}
void init()
{
	add_action("do_sao", "clean");
	add_action("do_sao", "sao");	
}
int do_sao(string arg)
{	 
	object me, weapon;
	int costj, costq,c_skill,c_exp;
	me = this_player();

	if(me->query_temp("job_name")!="打掃馬房") 
		return notify_fail("你必須跟館主領了這工作才能在這裏幹! \n");
	if(me->query_temp("mark/掃完了")) 
		 return notify_fail("你已經幹完活了，回去覆命(job ok)吧！\n");
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心幹活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "saozhou")
		return notify_fail("你想用什麼來打掃，用手掃嗎？\n");

	if ( !arg || arg != "馬房" ) return notify_fail("你要打掃什麼？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N腳一滑，不小心滑倒在糞堆裏，喫了一大口馬糞！\n",me);
		me->add("food", 10);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/掃") > 10 + random(10) &&
		present("mafang guanshi", environment(me)))
	{
		me->set_temp("mark/掃完了",1);
		message_vision(RED"馬房管事對$N説：乾的不錯，好了，你可以回去覆命(task ok)了。\n"NOR, me);
		return 1;
	}
	message_vision("$N找了個地方開始掃了起來，真夠臭的，你不由閉緊了呼吸。\n", me);
	me->start_busy(3);
	me->add_temp("mark/掃",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("club",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("club", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在掃地中對於棍的用法有些體會！\n"NOR);
		me->improve_skill("club", (int)(me->query("int") / 10));
	}
	return 1;
}



