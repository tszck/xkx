// Room: /d/nanshaolin/dmyuan2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void init()
{
	add_action("lingwu","lingwu");
}

void create()
{
	set("short", "達摩院後殿");
	set("long", @LONG
這是一座古樸的殿堂。西首的牆上掛滿了各類武功圖譜，不少白鬚
白眉的老僧們正端坐在圖譜畫軸之前，似乎在苦苦思索。南北山牆是高
及屋頂的大書架，走近細看，它們是各門各派的武功祕笈，屋正中擺着
幾張矮几訶和幾個團，幾位老僧正在入定中。
LONG );
	set("exits", ([
		"south" : __DIR__"dmyuan",
	]));
	set("coor/x", 1790);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!me->query("muren_winner"))
		return notify_fail("你未過木人巷，不能在此領悟。\n");
	if (!arg) return notify_fail("你要領悟什麼？\n");
	if (!me->query_skill(arg,1))
		return notify_fail("你不會這種技能。\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (arg == "force" )
		return notify_fail("你無法領悟基本內功。\n");
	if ((int)me->query("potential") -(int)me->query("learned_points") < 1 ) 
		return notify_fail("你從實戰中得到的潛能已經用完了。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("你只能從特殊技能中領悟。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 50)
	{
		me->receive_damage("jing",bl/5);
		return notify_fail("你沒辦法集中精神。\n");
	}
	sl=me->query_skill(special,1);
	if (sl > 200)
		return notify_fail("你的" +to_chinese(special)+"造詣已經很高了，不必再在這裏領悟什麼了。\n");
	if (bl > sl)
		return notify_fail("你的" +to_chinese(special)+"造詣不夠，無法領悟更深一層的"+to_chinese(arg)+"。\n");
	write("你瞑思苦想，對"+to_chinese(arg)+"的體會又深了一層。\n");
	if ((int)me->query("combat_exp",1) >850000)
	{
		me->receive_damage("jing",bl/5*3);
		me->add("learned_points", 1);
		me->improve_skill(arg, me->query_int()*3/2);
		me->start_busy(1);
		return 1;
	}
	me->receive_damage("jing",bl/5*2);
	me->add("learned_points", random(2));
	me->improve_skill(arg, me->query_int()*3/2);
	me->start_busy(1);
	return 1;
}

