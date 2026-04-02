// tianshan: /d/xingxiu/shanjiao.c
// Last Modified by winder on Feb. 28 2001
inherit ROOM;

void create()
{
	set("short", "天山腳下");
	set("long", @LONG
這裏是天山腳下，西面是高聳入雲的天山。天晴的時候可以看到山
頂上的冰川。一道天山將西域分為兩半。北疆是西域各族的聚居區，南
疆是無邊的塔克拉馬幹大沙漠。西南是通向天山南路回疆大草原的戈壁
沙漠。
LONG );
	set("exits", ([
		"westup"    : __DIR__"tianroad1",
//		"east"      : "/d/gaochang/road",
		"east"      : "/d/hasake/senlin1",

		"southwest" : "/d/huijiang/gebi1",
		"northeast" : __DIR__"yilihe",
		"southeast" : __DIR__"silk5",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xiyu" );
	set("objects", ([
		__DIR__"npc/trader" : 1,
		__DIR__"npc/hkid" : 1,
		__DIR__"npc/xxdizi1" : 1,
	]));
	set("coor/x", -40000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int current_water;
	object ob;
	if (dir == "southwest")
	{
		if (!userp(me)) return 0;
		current_water = me->query("water");
		if (current_water==0)
		{
		}

		if (current_water>0 && current_water<20)
		{
			me->set("water",0);
		}
		if (current_water>20)
		{
			me->set("water",current_water-20);
		}
		return ::valid_leave(me, dir);
	}
	if(me->query_temp("wait_target") &&
		objectp(present("anran zi", environment(me))))
		return notify_fail("黯然子閃身攔在你面前，喝道：臨陣想溜？給我滾回來！\n");
	if(me->query_temp("xx_rob") &&
		objectp(ob = present("hubiao biaoshi", environment(me))) &&
		ob->query("target") == me)
		return notify_fail("護鏢鏢師閃身攔住你的去路，看來是想把你給廢了！\n");  
	if(me->query_temp("xx_rob") && objectp(present("shangdui",environment(me))))
		return notify_fail("商隊在這裏呢，快搶(qiang)啊！\n");  
	return ::valid_leave(me, dir);
} 
