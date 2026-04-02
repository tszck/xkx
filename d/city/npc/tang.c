// tang.c 唐老闆 

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
int do_redeem(string arg);

void create()
{
	set_name("唐楠", ({ "tang nan", "tang" }));
	set("title", "當鋪老闆");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("str", 100);
	set("jing", 1000);
	set("qi", 1000);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_qi", 1000);
	set("long", "據說唐楠是四川唐家的後代。\n");
	set("no_get_from", 1);

//以下爲防止玩家運用特殊方法將當鋪老闆搬走。
	set("no_get", "1");

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}
void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
int do_redeem(string target)
{
	object dest, *all;
	int i, value;
	int per;

	all = users();

	if (!target) return notify_fail("你想贖誰？ 1\n");

	for(i=0; i<sizeof(all); i++) 
	{
//		if( target == (string)all[i]->id() || target == all[i]->name() )
		if( target == (string)all[i]->query("id") ||
			target == all[i]->query("name") )
			dest = all[i];
	}
	if( !dest || !this_player()->visible(dest))
		return notify_fail("唐楠說道：你說的人現在不在遊戲中，你過會再來吧。\n");
	else if( !dest->query_temp("selled"))
		return notify_fail("唐楠急道：你可別誣陷好人，我怎麼會非法扣押玩家呢！\n");

	if (query_temp("busy"))
		return notify_fail("喲，抱歉啊，我這兒正忙着呢……您請稍候。\n");
// value = dest->query("per")* 700;
  value = 10000;

  if (dest->query("gender") == "女性")
  {
  	per = dest->query("per");
    if ( per >= 0 && per <= 10 )
    value += per*100;          //0-10容貌 每點值一兩白銀
    if ( per >10 && per <= 20)
    value += (per-10)*10000; // 10-20 每點值一兩黃金
    if ( per > 20 && per <= 30)
    value += (per -20)* 100000;// 20-30 每點值十兩黃金
    if ( per > 30 )
    value += (per -30)* 10000000; //30-40 每點值 一千兩黃金 grin
                                 
  }
	switch (MONEY_D->player_pay(this_player(), value))
	{
		case 0:
			return notify_fail("贖金要"+MONEY_D->price_str(value)+"，沒錢就一邊待著去！\n");
		case 2:
			return notify_fail("您的零錢不夠了，銀票又沒人找得開。\n");
		default:
			set_temp("busy", 1);
			message_vision("$N從$n那裏贖回了一" + dest->query("unit") + dest->query("name") + "。\n", this_player(), this_object());
			dest->move(environment(this_player()));
			dest->set("startroom","/d/city/kedian");
			dest->delete_temp("selled");
			message("vision", HIY"只聽見嗖的一聲，一個遍體鱗傷的傢伙從天花板上掉了下來！\n" NOR, environment(dest), dest);
			tell_object(dest, "你被" + this_player()->query("name") + "贖了出來。\n");
	}
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);

	return 1;
}
