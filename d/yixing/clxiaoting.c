// /d/yixing/clxiaoting.c
// Last Modified by winder on Jul. 12 2002

#include <changle.h>
#define WOSHI   BANGS"clwoshi"
#define BANGZHU BANGS"npc/cl_situ"
inherit ROOM;
#include D_BEAUTY

void create()
{
	set("short", "小廳");
	set("long", @LONG
這是幫主及總管商討機密大事的所在，正中是一張太師椅，門上吊
着半舊的紅綢軟簾。牆上附庸風雅地掛着幾張山水字畫，一望可知均是
俗手之作。窗前幾盆菊花倒是十分繁茂。
LONG );
	set("exits", ([
		"south" : __DIR__"clzoulang2",
		"north" : __DIR__"clwoshi",
	]));
	set("objects",([
		__DIR__"npc/cl_situ" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	string beauty;
	object ob, leader, ling, *inv;
	int bonus, record;

	if( dir != "north" )
		return ::valid_leave(me, dir);
	if( !(ob = present("situ heng", environment(me))) )
		return ::valid_leave(me, dir);
	if( !living(ob) )
		return ::valid_leave(me, dir);

	if( ob->is_fighting() || ob->is_busy() )
		return notify_fail(sprintf("%s攔在你面前，喝道：" + RANK_D->query_rude(me) + "不得無禮！沒見幫主正忙着？\n", ob->name()));

	if( stringp(beauty = me->query_temp("bangs/beauty")) )
	{
		inv = all_inventory(this_object());
		for(int i = 0; i < sizeof(inv); i++)
		{
			if( (string)inv[i]->query("name") == beauty &&
				inv[i]->query_leader() == me )
			{
				message_vision("$N在$n的頭上彈了個清脆的腦崩兒，$n的腦門兒上立刻長出了個小臌包。\n", ob, me);
				return ::valid_leave(me, dir);
			}
		}
	}

	if( !userp(me) )
	{
		beauty = (string)me->query("name");
		if( intp(bonus = info_beauty[beauty]) &&
			leader = me->query_leader() )
		{
			if( userp(leader) &&
			(string)leader->query_temp("bangs/beauty") == beauty )
			{
				tell_object(leader, ob->name() + "説道：好！好！好！"+ob->query("party/party_name") + "上上下下幾千人中數你最討幫主的歡心！\n");
				leader->delete_temp("bangs/beauty");
				bonus = bonus * 25000 / (100000 + (int)leader->query("combat_exp"));
				record = bonus + random(bonus);
				leader->add("combat_exp", record);
				leader->add("shen", -record);
				write_file("/log/test/BangWomen",  sprintf("%s於%s時上貢%s得%s經驗點\n", leader->query("name"), ctime(time()), beauty, chinese_number(record)));
				if( ling = present("bang ling", leader) )
				{
					if( (string)ling->query("owner") ==
						leader->query("id") )
						ling->add("score", bonus/2 + random(bonus/2));
				}
				me->set_leader(0);
				remove_call_out("destroy_beauty");
				call_out("destroy_beauty", 1, me, leader);
				return ::valid_leave(me, dir);
			}
		}
	}
	return notify_fail(sprintf("%s攔在你面前，喝道：" + RANK_D->query_rude(me) + "不得無禮！後面是幫主的臥房。\n", ob->name()));
}

void destroy_beauty(object me, object leader)
{
	object room, ob;

	if( !me ) return;

	if( !leader ) { destruct(me); return; } 

	room = environment(me);
	if( base_name(room) != WOSHI ) { destruct(me); return; }
	if( room != environment(leader) ) { destruct(me); return; }
	if( !(ob = present("shijian", room)) ) { destruct(me); return; }
	if( !living(ob) ) { destruct(me); return; }
	message_vision("$N對$n喝道：我要給這位小姐更衣，你快出去吧！\n", ob, leader);
	message_vision("$N飛起一腳將$n踢了出去。\n", ob, leader);
	leader->move(this_object());
	message("vision", leader->name() + "被人從臥房中踢了出來，狼狽不堪。\n", this_object(), ({leader}));

	destruct(me);
}
