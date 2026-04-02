//Room: ztpo1.c 鑽天坡
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","鑽天坡");
	set("long",@LONG
蓮花石與洗象池之間，道路陡絕，石棧若齒，直上藍天，石蹬達一千三百
多級，是在陡峭山壁上開鑿出來的坡道。人行其上，前後頂踵相接，一如登天。
這段路叫「鵓鴿鑽天」，這段陡坡也因此而叫「鑽天坡」。這裏西上坡頂便到
洗象池，東下可達蓮花石。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"eastdown" : __DIR__"lianhuashi",
		"westup"   : __DIR__"ztpo2",  
	]));
	set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1080);
	set("coor/z", 110);
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

