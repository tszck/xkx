// heersu.c
#include <ansi.h>
inherit NPC;
string ask_me();
string ask_he();

void create()
{
	set_name("赫爾蘇", ({"heersu"}));
	set("gender", "男性");
	set("age", 65);
	set("long", "他是一個老參客，可是看起來卻一貧如洗。據江湖傳言，他藏有不少珍貴的人蔘首烏之類的寶貨。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);

	set("inquiry",([
		"人蔘"   : (: ask_me :),
		"山參"   : (: ask_me :),
		"老山參" : (: ask_me :),
		"參"     : (: ask_me :),
		"何首烏" : (: ask_he :),
		"首烏"	 : (: ask_he :)
	]));
	set("item_count",1);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
	object me = this_player();
	if ((int)(me->query("shen") < 0))
		return "你又來搶參啦，早被搶光了，沒有了。\n";
	me->set_temp("heersu", "人蔘");
	return "那你就拿出錢來吧。\n";
}
string ask_he()
{
	object me = this_player();
	if((int)(me->query("shen") < 0))
		return "你又來搶首烏啦，早被搶光了，沒有了。\n";
	me->set_temp("heersu", "首烏");
	return "那你就拿出錢來吧。\n";
}

int accept_object(object me, object ob)
{
	object obj;
	if ( !me->query_temp("heersu") )
	{
		message_vision("赫爾蘇惶恐地對$N説：我不敢要您老的錢。\n", me);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 50000)
	{
		if (me->query_temp("heersu") == "首烏")
		{
			if (query("item_count")>0)
			{
			message_vision("赫爾蘇對$N説：好！既然這位"+RANK_D->query_respect(me)+"如此看得起我老頭子，\n這棵首烏我留了很久了，就送給你吧！\n",me);
				me->delete_temp("heersu");
				obj = new("/clone/medicine/vegetable/heshouwu");
				obj -> move(me);
				add("item_count", -1);
			}
			else message_vision("赫爾蘇對$N説：錢我先收着，有首烏時再説吧！\n", me);
		}
		else
		{
			if (query("item_count")>0)
			{
			message_vision("赫爾蘇對$N説：好！既然這位"+RANK_D->query_respect(me)+"如此看得起我老頭子，\n這棵參我留了很久了，就送給你吧！\n",me);
				me->delete_temp("heersu");
				obj = new("/clone/medicine/vegetable/renshen");
				obj -> move(me);
				add("item_count", -1);
			}
			else message_vision("赫爾蘇對$N説：錢我先收着，我一定找個最大的老山參給您！\n", me);
		}
	}
	else message_vision("赫爾蘇皺眉對$N説：您給的也太少了吧？\n", me);
	return 1;
}

