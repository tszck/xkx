// wg_caidi2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
這裏是塊菜地，菜地旁有幾口大缸，裏面盛滿了水，可是菜地看起
來都乾裂了，幾棵菜蔫蔫的長着，看樣子是缺水太多了。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_houyuan3",
	]));
	set("objects", ([
		__DIR__"npc/wg_guanjia6" : 1,
		__DIR__"npc/wg_kunlundizi" : 1,
	]));
	set("outdoors", "wuguan");
 	set("coor/x", 81);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
	add_action("do_jiao", "澆");	 
}
int do_jiao(string arg)
{
	object me, weapon;
	int costj, costq;
	me = this_player();

	if(me->query_temp("job_name")!="澆菜地") 
		return notify_fail("你必須跟館主領了這工作才能在這裏幹活！\n");
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心幹活！\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "piao")
		return notify_fail("你想用什麼來舀水澆，用手嗎？\n");
	if ( !arg || arg != "水" ) return notify_fail("你要澆什麼？\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N彎腰到大缸裏舀水，結果一失足栽進了缸裏！\n",me);
		me->set("water", 350);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/澆") > 10+(random(5)) &&
		present("caiyuan guanshi", environment(me)))
	{
		me->set_temp("mark/澆完了",1);
		message_vision(RED"菜園管事對$N說：乾的不錯，好了，你可以回去覆命(job ok)了。"NOR, me);
		return 1;
	}
	message_vision("$N用瓢從缸裏舀起水，在菜地裏澆起水來。 \n", me);
	me->start_busy(3);
	me->add_temp("mark/澆",1);
	return 1;
}

