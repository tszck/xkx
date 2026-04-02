// wg_caidi1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
這裏是塊菜地，由於長期得不到良好的照顧，菜地裏雜草叢生，種
的菜都長勢不好，蔫蔫的，地都荒了。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan3",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia5" : 1,
		__DIR__"npc/wg_nsldizi":1,
	]));
	set("outdoors", "wuguan");
 	setup();
}

void init()
{
	add_action("do_chu", "chu");
	add_action("do_chu", "鋤");	
}
int do_chu(string arg)
{
	object me,weapon;
	int costj, costq,c_exp,c_skill;
	me = this_player();

	if(me->query_temp("job_name")!="鋤草") 
		return notify_fail("你必須跟館主領了這工作才能在這裏幹活！\n");
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心幹活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "chutou")
		return notify_fail("你想用什麼來鋤草，用手嗎？\n");
	if ( !arg || arg != "草" ) return notify_fail("你要鋤什麼？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N手一鬆，不小心鋤在了自己的腳上！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/鋤") > 10+(random(10)) &&
		present("caiyuan guanshi", environment(me)))
	{
		me->set_temp("mark/鋤完了",1);
		message_vision(RED"菜園管事對$N說：乾的不錯，好了，你可以回去覆命(job ok)了。"NOR, me);
		return 1;
	}
	message_vision("$N揮起鋤頭，對着地上的雜草鋤了起來。\n", me);
	me->start_busy(3);
	me->add_temp("mark/鋤",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("staff",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("staff", 1) < 30 && random(10)>5 )
	{
		write(HIM"你在鋤草中對於杖的用法有些體會！\n"NOR);
		me->improve_skill("staff", (int)(me->query("int") / 10));
	}
	return 1;
}

