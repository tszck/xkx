//Room: lianhuashi.c 蓮花石
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","蓮花石");
	set("long",@LONG
這是蓮花石。此處岩石紋理縱橫，形似蓮花，顏如芙蓉，彷彿萼瓣層疊，
細蕊欲綻。上有一庵，叫「蓮花社」。由此往西上直達洗象池，東下左通華嚴
頂，右通九老洞。
LONG);
	set("objects", ([
		CLASS_D("emei") + "/su" : 1,
		CLASS_D("emei") + "/ling" : 1,
	]));
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"southeast" : __DIR__"jldongkou",
		"eastdown"  : __DIR__"huayanding",
		"westup"    : __DIR__"ztpo1",  
	]));
	set("coor/x", -6190);
	set("coor/y", -1080);
	set("coor/z", 100);
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
			tell_object(me,"你在鑽天坡往上爬了一陣，好累人。\n");
		}
	}
	return 1;
}
