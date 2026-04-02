// Room: /d/nanshaolin/xjchu.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
int do_pi(string arg);
void create()
{
	set("short", "香積廚");
	set("long", @LONG
一間不大的小屋，正中擺着一口大鐵鍋，正冒着騰騰的熱氣，一股
粥香瀰漫在室內。幾個火工正在忙着加柴，煽火，全寺弟子做完早課都
要喝粥。一位侍粥僧揮舞着沉重的大鐵勺，正在喫力的攪動着粥湯。
LONG );
	set("exits", ([
		"south"  : __DIR__"zhaitang",
	]) );
	set("objects", ([
		__DIR__"npc/szseng" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_ao", "ao");
	add_action("do_ao", "熬");
}
int do_ao(string arg)
{
	object /*ob,*/ me = this_player();
	int costj, costq,times,lvl1,lvl2,exp;

	exp = me->query("combat_exp");
	lvl1 = me->query_skill("hand",1);
	lvl2 = me->query_skill("finger",1);
	if(me->query_temp("job_name")!="熬粥") 
		return notify_fail("廚房可不是鬧着玩的地方，你還是走開吧！\n");
	if (me->is_busy())
	{
		write("你現在正忙着呢！\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("你正在戰鬥中,無法專心幹活！\n");
		return 1;
	}
	if ( !arg || arg != "粥" )
	{   
		message_vision("$N要做什麼？\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(10);
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N手一鬆，掉進鍋裏。\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);	
	if (((int)me->query_temp("mark/做")>times) &&
		(present("shizhou seng", environment(me))))
	{
		me->add("potential",(int)(me->query_skill("buddhism",1)/5)+30);
		me->add("combat_exp",(int)(me->query_skill("buddhism",1)/5)+60);
		me->delete_temp("job_name");
		me->delete_temp("mark");
		return notify_fail(RED "侍粥僧説道：多謝你來幫我的忙，還是快回去吧！！！\n"NOR);
	}
	me->start_busy(1);
	message_vision("$N身形一抖，雙腳勾住房梁，倒懸在空中，接過鐵勺用力攪拌粥鍋。\n", me);
	me->add_temp("mark/做",1);
	if ( (int)me->query_skill("hand", 1) < 20 && random(10)>6 )
	{
		if(lvl1 * lvl1 * lvl1 / 10 < exp)
		{
			write(HIM"你在揮舞鐵勺中，對手上功夫有些領悟！\n"NOR);
			me->improve_skill("hand", (int)(me->query_skill("buddhism",1) / 5));
		}
		if(lvl2 * lvl2 * lvl2 / 10 < exp)
		{
			write(HIM"你在揮舞鐵勺中，對指上功夫有些領悟！\n"NOR);
			me->improve_skill("finger", (int)(me->query_skill("buddhism",1) / 5));
		}
	}
	return 1;
}