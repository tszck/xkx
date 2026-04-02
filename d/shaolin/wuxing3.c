// Room: /d/shaolin/wuxing3.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIR "五行洞" NOR);
	set("long", HIR @LONG
這是五行洞。進來頓覺一股熱浪撲面而來，衝得你差點暈了
過去。四周一片通紅，地面上冒着絲絲白氣，腳底劇烈的炙痛使
你幾乎立腳不住。熱風帶着隆隆巨響衝擊着耳鼓，令你覺得置身
洪爐之中，全身的水分都在被一滴滴地烤乾。牆角上幾具枯柴般
的乾屍就證明瞭這一點。
LONG
NOR	);
	set("exits", ([
		"east" : __DIR__"wuxing1",
		"south" : __DIR__"wuxing2",
		"west" : __DIR__"wuxing0",
		"north" : __DIR__"wuxing4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 785);
	set("coor/z", 100);
	set("no_quest",1);
	setup();
}

int check_out(object me)
{
	int metal, wood, water, fire, earth;

	metal = me->query_temp("wuxing/金");
	wood = me->query_temp("wuxing/木");
	water = me->query_temp("wuxing/水");
	fire = me->query_temp("wuxing/火");
	earth = me->query_temp("wuxing/土");

	if ( metal > 0 &&
		metal == wood && metal == water &&
		metal == fire && metal == earth )
	{
		me->delete_temp("wuxing");
		me->move(__DIR__"andao2");
		return (1);
	}
	return (0);
}

int valid_leave(object me, string dir)
{
	int count;

	if (member_array(dir, dirs) != -1)
	{
		if (dir == "north")
		{
//			write("*火生土*\n");
			count = me->query_temp("wuxing/土");
			count++;
			me->set_temp("wuxing/土", count);
			if (check_out(me))
				return notify_fail("你順利地走出了五行迷宮。\n");
		}
		else if (dir == "west")
		{
//			write("*火克金*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("你掉進機關，落入僧監。\n");
		}
	}
	return ::valid_leave(me, dir);
}