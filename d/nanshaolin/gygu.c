// Room: /d/nanshaolin/gygu.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","歸元谷");
	set("long", @LONG
走出石室，只見在一深谷之內。前面一座高峯阻路，拔地而起，直
矗天半。四周峯巒都似向它躬揖，谷面內不過十畝方圓地面，怪松奇石，
株株不同。蒼皮鐵磷，虯幹龍枝，似欲臨風飛去。
LONG );
	set("exits", ([
		"southeast" : __DIR__"xclang",
	]));
	set("outdoors","nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_chop","kan");
}
int do_chop(string arg)
{
	object weapon, me=this_player();
	int lvl, exp;

	lvl = me->query_skill("ranmu-blade", 1);
	exp = me->query("combat_exp");
	weapon=me->query_temp("weapon");
	if (!arg) return 0;
	if (arg!="tree") return 0;
	if (!(me->query("pass_xin"))) return 0;
	if (!weapon || weapon->query("id") != "chai dao")
		return notify_fail("你要用柴刀劈樹。\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你覺得好累，全身沒力氣。\n");
	if ((int)me->query("neili",1) < 100)
		return notify_fail("你的內力不夠。\n"); 
	message_vision (RED"$N使開柴刀對準崖邊怪松，一刀刀劈去，\n松木堅韌，刀光籠罩之下，火星四濺，發出\n闢扒燃燒之聲。\n" NOR,me);
	me->receive_damage("qi", 50);
	me->add("neili", -50);
	if (lvl*lvl*lvl/10 < exp)
	{
		me->improve_skill("ranmu-blade", ((int)me->query_skill("blade",1))/4);
	}
	return 1;
}

