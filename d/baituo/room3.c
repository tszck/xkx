// Room: /d/baituo/room3.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
int do_da(string arg);
void create()
{
	set("short","練功室");
	set("long", @LONG
這裏是白駝山弟子的練功室。這個練功室空無一人，只有幾個大大
的木樁(zhuang)立在屋子當中。
LONG	);
	set("exits",([
		"out" : __DIR__"liangong",
	]));
	set("item_desc", ([
		"zhuang":"一個木樁，做成木人的樣子固定在地上，供人擊打(da)練功。\n",
	]));     
	set_temp("full",0);
	set("no_clean_up", 0);
	set("coor/x", -49990);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
}

void init()
{
	object ob=this_player();
	if((int)query_temp("full")==2)
	{
		message_vision("$N一見房間裏已經有人了，只好退了出去。\n",ob);
		ob->move(__DIR__"liangong");
		return;
	}
	add_temp("full" ,1);
	add_action("do_da", "da");
	return;
}

int valid_leave(object who, string dir)
{
	add_temp("full",-1);
	return 1;
}
int do_da(string arg)
{
	object me = this_player();
	int jing1, qi1, exp, lvl;
	object weapon;

	exp = me->query("combat_exp");
	lvl = me->query_skill("staff",1);
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心練功！\n");
	if (!living(me)) return notify_fail("你發瘋了？\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("空手是練不了杖法的。\n");
	if (!arg || arg!="zhuang") return notify_fail("你要打什麼？打人嗎？\n");
	jing1 = random((int)me->query("con"))+1;
	qi1 = random((int)me->query("str"))+1;
	if ((int)me->query("jing") < jing1 || (int)me->query("qi") < qi1)
	{
		message_vision("$N馬步一鬆，一不小心腦袋撞在了木樁上！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", jing1);
	me->receive_damage("qi", qi1);       
	message_vision("$N站好馬步，提起鋼杖，開始和木樁對打起來。\n", me);
	if ( lvl < 30 && lvl*lvl*lvl/10 < exp && random(10) > 4 )
	{
		me->improve_skill("staff", (int)(me->query("int") / 5));
	}
/*
	if ( (int)me->query("combat_exp") < 30000) 
	{
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("int") / 10)));
	}
*/
	return 1;
}

