//RJQJIGUAN.C

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
這裏是一條祕道的盡頭，石牆之上嵌入兩盞油燈，火苗幽藍，向北
望去，黑暗中有些光亮。
LONG );
	set("exits", ([
		"north" : __DIR__"rjqmishi",
//		"down" : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 850);
	set("coor/z", 60);
	setup();
}

void init()
{
	object me;
	int q,d,eq;
	me=this_player();
	q=(int)me->query("max_qi");
	d=(int)me->query_skill("dodge");
	if(((int)me->query("mingjiao")!=1)&&(d<=100))
	{
		message_vision("$N只覺猶如利刃加身，噴血而出，渾身被射成刺蝟一般\n",me);
		eq=(int)me->query("qi")-q+(int)(q*d/100);
		me->set("qi",eq);
		me->set("eff_qi",eq);
	}
	if (eq<=0) me->die();
}