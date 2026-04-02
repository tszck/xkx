//Room: wannianan.c 萬年庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","萬年庵");
	set("long",@LONG
萬年庵建在一座突起的山峯上，周圍古木森森，清泉淙淙，閒步無坎，吟
遊無坷，景色非常迷人。由此西上過十二盤可達華嚴頂，南下至白龍洞。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"bailongdong",
		"westup"    : __DIR__"shierpan1",
		"enter"     : __DIR__"wnadian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1060);
	set("coor/z", 60);
	setup();
}

int valid_leave(object me, string dir)
{
	int c_exp,c_skill;

	if (dir == "westup" && userp(me))
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

