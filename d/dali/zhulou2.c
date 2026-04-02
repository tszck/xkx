//Room: /d/dali/zhulou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","竹樓");
	set("long",@LONG
一間標準的臺夷竹樓，四面牆壁皆是竹子，正中砌了一座正方形
的竈臺，其內架置着鐵爐。夷族傳統席地而睡，是以屋內無牀，延牆
擺有墊褥，屋舍內除了石堆祭臺外別無傢俱。
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"   : __DIR__"zhulou1",
	]));
	set("coor/x", -41010);
	set("coor/y", -79000);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
	{
		me->set_temp("dali_xc/zl2",1);
	}
}