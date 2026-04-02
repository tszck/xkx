// Room: /d/xingxiu/shanbi.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "山壁");
	set("long", @LONG
一條草草在山壁上人工開鑿出來崎嶇的小路，幾個星宿弟子正在埋
頭苦幹。這裏，寒風凜冽，西面是望浩浩百里方圓的星宿海。東邊山壁
上，盡是星宿弟子用力砸出的坑凹(ao)。
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"xiaolu",
	]));
	set ("item_desc", ([
		"ao" : "是人用棍杖撞擊(za)山壁(bi)留下的痕跡。\n"
	])) ;
	set("objects", ([
		__DIR__"npc/gushou"  : 1,
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -49900);
	set("coor/y", 20300);
	set("coor/z", 100);
	setup();
}

void init()
{
	add_action("do_za", "za");
}

int do_za(string arg)
{
	object  weapon, me = this_player();
	int ging_cost, qi_cost, jingli_cost;
	weapon = me->query_temp("weapon");
	ging_cost = 150 / (int)me->query("int");
	qi_cost = 200 / (int)me->query("con");
 
	if (!living(me)) return 0;
	if ( arg != "bi" ) return notify_fail("你要撞擊什麼？\n");
	if (!weapon) return notify_fail("你用什麼砸山壁來練功？\n");  
	if (weapon->query("skill_type") == "staff")
		if ((int)me->query_skill("staff", 1) >= 120) 
			return notify_fail("你已經不用再在這裏費功夫了。\n");  
	if(weapon->query("skill_type") == "hammer")
		if ((int)me->query_skill("hammer", 1) >= 120) 
			return notify_fail("你已經不用再在這裏費功夫了。\n");  
	if (random((int)me->query("kar")) < 3 )
	{
		message_vision("$N一不小心砸到自己腳上，痛得暈了過去。\n",me);
		me->unconcious();
		return 1;
	}
	if((me->query("jing") < ging_cost) || (me->query("qi") < qi_cost))
	{
		message_vision("$N猛地砸在山壁上，結果用力過度！\n", me);
		me->unconcious();
		return 1;
	}
	message_vision("$N使勁撞擊山壁，在山壁上砸出一個坑凹。\n", me);
	if(weapon->query("skill_type") == "staff")
		me->improve_skill("staff", me->query_skill("staff", 1));
	else if(weapon->query("skill_type") == "hammer")
	me->improve_skill("hammer", me->query_skill("hammer", 1));
	me->receive_damage("jing", ging_cost );
	me->receive_damage("qi", qi_cost );
	return 1;     
}
