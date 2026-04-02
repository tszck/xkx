// Last Modified by Sir on 9/17/2001
// wg_wuchang1.c

#include <ansi.h>
inherit ROOM;
int do_da(string arg);

void create()
{
	set("short", "北練武場");
	set("long", @LONG
這是間大大的房子，十分寬闊，不少人在這裏汗流浹背的苦練着功
夫，地上有一些練武用的工具，牆邊擺者一排木人樁(muren zhuang)。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wuchang3",
		"south" : __DIR__"wg_lang1",
	]));
	set("item_desc", ([
		"muren zhuang" : "一個木樁，做成木人的樣子固定在地上，供人擊打(da)練功。\n",
	]));
	set("outdoors", "wuguan"); 
	set("objects", ([
		__DIR__"npc/wg_xxdizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_da", "da");
	
}
int do_da(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill;

	me = this_player();
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心練功！\n");
	if ( !living(me)) return notify_fail("你發瘋了？\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打木人樁。\n");
	if (!arg || arg != "muren zhuang")
		return notify_fail("你要打什麼？打人嗎？\n");
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N馬步一鬆，一不小心腦袋撞在了木人樁上！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	message_vision("$N站好馬步，運氣於拳，開始和木人樁對打起來。\n", me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("cuff",1);
	if ( (int)me->query("combat_exp") < 50000)
	{
		if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
			(int)me->query_skill("cuff", 1) < 30 && random(10)>6 )
		{
			write(HIM"你在和木人樁的對打中領悟了不少基本拳法！\n"NOR);
			me->improve_skill("cuff", (int)(me->query("int") / 5));
		}	
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("int") / 10)));
	}
	return 1;
}
