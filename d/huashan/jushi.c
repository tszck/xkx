// jushi.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "居室");
	set("long", @LONG
這裏是嶽夫人的寢室，嶽夫人在江湖上人稱「淑女劍」，為人極有
骨氣，她的居室卻相當樸素，牀椅之外，靠碧紗窗(window)處有個梳妝
臺(tai)， 牆上掛着一口寶劍(sword)， 蛇皮吞口，看來很是鋒利。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"changlang",
	]));
	set("objects", ([
		CLASS_D("huashan") + "/yue-wife" :1,
	]));
	set("item_desc", ([
		"window" : "窗外就是天聲峽了。往外望去，雲深谷幽令人目眩。\n",
		"sword"  : "這是上次前往福建時帶回的龍泉劍。\n",
		"tai"    : "這是一張紅漆梳妝枱，半開的抽屜斜插着幾朵鮮花。\n"
	]));
	set("coor/x", -880);
	set("coor/y", 230);
	set("coor/z", 120);
	setup();
}
void init()
{
	add_action("do_move", "push");
	add_action("do_move", "move");
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_move(string arg)
{
	object paper, me=this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="tai" )
	{
		if ((me->query("family/master_id") !="yue wife") &&
			objectp(present("yue wife", environment(me))))
		{
			return notify_fail("嶽夫人喝道：這位" + RANK_D->query_respect(me) + "，你不能隨便翻人家東西。\n");
			return 1;
		}
		if (!query("had_yunu"))
		{
			message_vision("$N輕輕的拉開抽屜，發現裏面有一本書...。\n", me);
			paper = new("/clone/book/yunu_book");
			paper->move(__FILE__);
			message("channel:rumor", MAG"【謠言】某人："+me->query("name")+"拿到玉女劍譜啦。\n"NOR, users());
			set("had_yunu", 1);
			return 1;
		}
		message_vision("$N輕輕的拉開抽屜，可是裏面啥都沒有...。\n", me);
		return 1;
	}
	return 0;
}

int do_pick(string arg)
{
	object sword, me=this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="sword" )
	{
		if ((me->query("family/master_id") !="yue wife") &&
			objectp(present("yue wife", environment(me))))
		{
			return notify_fail("嶽夫人喝道：這位" + RANK_D->query_respect(me) + "，你不能隨便翻人家東西。\n");
			return 1;
		}
		if (!query("had_sword"))
		{
			sword = new(WEAPON_DIR"treasure/longquan-jian");
			if ( sword->violate_unique() ) destruct( sword );
			else
			{
				message_vision("$N輕輕的摘下寶劍，哈哈，真開心...。\n", me);
				sword->move(me);
				message("channel:rumor", MAG"【謠言】某人："+me->query("name")+"搶了一口龍泉劍啦。\n"NOR, users());
				set("had_sword", 1);
				return 1;
			}
		}
		message_vision("$N伸手去摘寶劍，才發現只剩劍鞘了，寶劍早就被別人取走了...。\n", me);
		return 1;
	}
	return 0;
}
