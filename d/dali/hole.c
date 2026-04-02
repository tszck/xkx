//Room: /d/dali/hole.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","大，小芝雲洞");
	set("long",@LONG
帶着火折進入洞內，迂迴蛇行，不久，即見一廳豁然開朗，石鍾
乳，石筍，石柱，玲瓏剔透，鬥奇爭勝。光照壁影，如月穿曉巖，溪
雲接水，壁氣侵寒，石光滴翠，清幽可愛。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "out"      : __DIR__"changhu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38000);
	set("coor/y", -53990);
	set("coor/z", 30);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/zyd",1);
	}
}