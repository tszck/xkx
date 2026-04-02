#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "木房");
	set("long", @LONG
一進屋，你就被巨大的轟鳴聲吵住了，這裏堆了好多長的木頭，準
備要做柴火用的，但是在送去柴房前先得把長木頭鋸短成一截截的，才
好用斧頭劈開。你看見幾個人在費力的鋸着。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan2",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia2" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_pi", "ju");
	add_action("do_pi", "鋸");	
}

int do_pi(string arg)
{ 
	object me,weapon;
	int costj, costq,i,c_exp,c_skill;
	i=0;
	me = this_player();

	if(me->query_temp("job_name")!="鋸木頭") 
		return notify_fail("你必須跟館主領了這工作才能在這裏幹! \n");
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心幹活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "juzi")
		return notify_fail("你想用什麼來鋸木頭，用手掰嗎？\n");

	if ( !arg || arg != "木頭" ) return notify_fail("你要鋸什麼？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("木頭突然斷了，$N一沒留神，讓彈起來的木頭砸在了頭上！\n",me);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/鋸") > 10 + random(10) &&
		present("mufang guanshi", environment(me)))
	{
		me->set_temp("mark/鋸完了",1);
		message_vision(RED"木房管事對$N説：乾的不錯，好了，你可以去張總管那覆命(job ok)了。"NOR, me);
		return 1;
	}
	message_vision("$N擺正一根木頭，慢慢鋸了起來。\n", me);
	me->start_busy(3);
	me->add_temp("mark/鋸",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("hand",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("hand", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在鋸木頭的推拉中對基本手法有些體會！\n"NOR);
		me->improve_skill("hand", (int)(me->query("int") / 10));
	}
	return 1;
}
