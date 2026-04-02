//Room: qianfoan.c 千佛庵
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","千佛庵");
	set("long",@LONG
此處是洪椿坪千佛庵。山間小坪壩，四面層巒迭嶂，峯環嶺護；兩側深谷
幽嵐，溪澗玲叮。坪上古木扶疏，亭亭如蓋，山陰沁透，白霧飄遊，極為幽靜
清涼。此處常見雨霧霏霏，林中迷迷濛濛，乃山中霧氣所為。正所謂「山行本
無雨，空翠濕人衣」。這就是譽為奇觀的「洪椿曉雨」。此處殿美景幽，氣象
新異，令人心醉。沿途南上是「九十九道拐」，北下經黑龍江棧道至清音閣。
LONG);
	set("outdoors", "emei");
	set("exits",([ /* sizeof() == 1 */
		"southwest" : __DIR__"jsjdg1",
		"enter"     : __DIR__"qfadadian",
		"north"     : __DIR__"heilong2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1060);
	set("coor/z", 80);
	setup();
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
			tell_object(me,"你沿九十九道拐又向上爬了一陣，覺得好累。\n");
		}
	}
	return 1;
}

