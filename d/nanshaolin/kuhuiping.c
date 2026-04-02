// Room: /d/nanshaolin/kuhuiping.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"苦慧坪"NOR);
	set("long", @LONG
你心智一清原發現自己竟在一座崖壁之上，兩面高巖中藏廣壑，壑
底雲氣濛濛，其深無際。巖壁間橫着幾條羊腸野徑，素無人蹤。巖壁上
滿生雜草藤蔓，地勢異常險峻。苦慧禪師當年負氣私自離寺出走，想是
自此密徑離去，創下了西域少林一派。據説後世高僧已將密徑堵絕，從
此處再無出路，只餘當年苦慧攀過的蔓藤野徑，留待後人。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("outdoors","nanshaolin");
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_pan","pan");
}
int do_pan(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("leg", 1), exp = me->query("combat_exp");
	if (arg!="teng") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"雙腿攀住了蔓藤，向野徑爬去。\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"你腿上無力，只攀住一下變被摔脫。\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你經驗不足，只攀住一下變被摔脫。\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"你雙腿尚未攀到，身形已借腿力飄上了小徑。\n"NOR);
		return 1;
	}
	if (lvl >= 30 && lvl <= 100&&arg=="teng" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("leg", (me->query("int"))*3/2);
		write(HIR"你雙腿一縱已攀住了蔓藤，全身借腿力緩緩移向小徑，你自覺腿力頗有精進。\n"NOR);
		return 1;
	}
}

