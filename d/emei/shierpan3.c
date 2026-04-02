//Room: shierpan3.c 十二盤
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","十二盤");
	set("long",@LONG
這裏石階陡折多彎，號稱「十二盤」。你見路邊有個八音池，有人正在向
池中擊掌(clap)。由此西上可達華嚴頂，東下則到萬年庵。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"shierpan2",
		"southwest" : __DIR__"shierpan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6160);
	set("coor/y", -1070);
	set("coor/z", 80);
	setup();
}
void init()
{
	add_action("do_clap", "clap");
}

int do_clap()
{
	object me = this_player();
	int c_exp,c_skill;
 
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("strike",1);
	write("池內忽然有蛙大鳴一聲，接着羣蛙次第相合，最後又是一蛙大鳴，羣蛙便嘎然\n");
	write("而止，其數正好爲八。\n");
	if ( me->query("qi") < 10 )
		 me->unconcious();
	else
	{
		if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill< 101)) 
		me->improve_skill("strike", (int)me->query_skill("strike", 1));
		me->receive_damage("qi", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "southwest" && userp(me))
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		if ( me->query("qi") < 10 ) me->unconcious();
		else
		{
			me->receive_damage("qi", 10);
			if (((c_skill*c_skill*c_skill/10)< c_exp) &&
				(c_skill < 101))
				me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
			tell_object(me,"你爬上了十二盤，覺得上山的路又陡又彎，好累人。\n");
		}
	}
	return 1;
}
