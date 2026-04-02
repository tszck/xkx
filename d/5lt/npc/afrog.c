// afrog.c

#include <ansi.h>
inherit NPC;

int ask_me();
int ask_heal();
int ask_poison();

void create()
{
	set_name("青蛙", ({ "afrog" }));
	set("title", "診所醫生");
	set("gender", "男性");
	set("long", "青蛙抬頭看了你一眼，眼角流露出平和的笑容，讓再緊張的病人見到心情也隨之平靜了許多。\n");
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);

	set_skill("unarmed", 100);
	set_skill("medicine", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 50);
	set("count", 30);
	set("inquiry", ([
		"療傷"   : (: ask_me :),
		"治病"   : (: ask_heal :),
		"解毒"   : (: ask_poison :),
	]));

	set("party/party_name", HIB"華山派"NOR);
	set("party/rank", HIW"第二代弟子"NOR);
	create_family("華山派", 2, "弟子");
	setup();

	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int ask_me()
{
	object ob = this_player();
	object me = this_object();
	object where;

	if(me->is_fighting())
	{
		command("say 我現在沒空！\n");
		return 1;
	}
	if(me->query("count") < 1)
	{
		command("say 傷藥都用完了，我還沒來得及配，你一會再來吧。\n");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{
		command("say 你這點江湖閲歷，也想讓我為你療傷？\n");
		return 1;
	}
		
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
	{
		command("?"+ob->query("id"));
		command("say 你沒有受任何傷啊？\n");
		return 1;
	}
	else
	{
		message_vision("青蛙喂$N服下一顆藥丸，然後盤膝坐下，雙掌貼着$N的背心。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		        ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{
			where = environment(me);
			remove_call_out("newyao");
			call_out("newyao",600,me);
		}
		return 1;
	}
}

int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));
	message_vision("大約過了一盅茶的時份，青蛙慢慢地站了起來。\n",ob);
	command("say 你的傷勢已經全好了,可以走啦。\n");
	return 1;
}

int newyao(object me)
{
//	object where = environment(me);
	me->add("count",20);
	return 1;
}
	
int ask_heal()
{
	object ob = this_player();
	object me = this_object();
//	object where;

        if(me->is_fighting())
        {
		command("say 我現在沒空！\n");
		return 1;
	}

	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{       
		command("say 你這點江湖閲歷，也想讓我為你治病？\n");
		return 1;
	}
		
	if( ob->query_condition("ill_kesou") ||
		ob->query_condition("ill_zhongshu") ||
		ob->query_condition("ill_shanghan") ||
		ob->query_condition("ill_dongshang") ||
		ob->query_condition("ill_fashao"))
	{
		message_vision("平一指輕釦$N脈門，略一思索，隨後轉身從藥簍裏取出幾味草藥，開始為$N熬藥。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);		
		return 1;
	}
	
	else
	{
		command("?"+ob->query("id"));
		command("say 看你的氣色，並沒有生病啊？\n");
		return 1;
	}
	
}
int recover_II(object ob)
{
	if (ob->query_condition("ill_kesou"))
		ob->clear_condition("ill_kesou",0);
	if (ob->query_condition("ill_zhongshu"))
		ob->clear_condition("ill_zhongshu",0);
	if (ob->query_condition("ill_shanghan"))
		ob->clear_condition("ill_shanghan",0);
	if (ob->query_condition("ill_dongshang"))
		ob->clear_condition("ill_dongshang",0);
	if (ob->query_condition("ill_fashao"))
		ob->clear_condition("ill_fashao",0);
	message_vision("大約一柱香過後，青蛙讓你喝下一碗剛熬好的熱氣騰騰的中藥。\n",ob);
	command("say 你的身體已無大礙,可以走啦。\n");
	return 1;
}

int ask_poison()
{
	object ob = this_player();
	object me = this_object();
//	object where;

        if(me->is_fighting())
	{
		command("say 我現在沒空！\n");
		return 1;
	}

	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{
		command("say 你這點江湖閲歷，也想讓我為你解毒？\n");
		return 1;
	}
		
	if(ob->query_condition("chanchu_poison") ||
		ob->query_condition("drunk") ||
		ob->query_condition("flower_poison") ||
		ob->query_condition("ice_poison") ||
		ob->query_condition("iceshock") ||
		ob->query_condition("rose_poison") ||
		ob->query_condition("scorpion_poison") ||
		ob->query_condition("slumber_drug") ||
		ob->query_condition("snake_poison") ||
//		ob->query_condition("ss_poison") ||
		ob->query_condition("wugong_poison") ||
//		ob->query_condition("xx_poison") ||
		ob->query_condition("xiezi_poison") ||
		ob->query_condition("zhizhu_poison") ||
		ob->query_condition("zhua_poison") ||
		ob->query_condition("ice_sting"))
	{
		message_vision("青蛙輕釦$N脈門，雙眉深鎖，隨後喂$N服下一顆藥丸，盤膝坐下，雙掌貼着$N的背心，開始為$N解毒。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			ob->add("score",-200);    
		}
		me->add("count", -1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);		
		return 1;
	}
	else
	{
		command("?"+ob->query("id"));
		command("say 看來我幫不了你什麼忙了！\n");
		return 1;
	}
}
int recover_III(object ob)
{
	if (ob->query_condition("chanchu_poison"))
		ob->clear_condition("chanchu_poison",0);
	if (ob->query_condition("drunk"))
		ob->clear_condition("drunk",0);
	if (ob->query_condition("flower_poison"))
		ob->clear_condition("flower_poison",0);
	if (ob->query_condition("ice_poison"))
		ob->clear_condition("ice_poison",0);
	if (ob->query_condition("iceshock"))
		ob->clear_condition("iceshock",0);
	if (ob->query_condition("rose_poison"))
		ob->clear_condition("rose_poison",0);
	if (ob->query_condition("scorpion_poison"))
		ob->clear_condition("scorpion_poison",0);
	if (ob->query_condition("slumber_drug"))
		ob->clear_condition("slumber_drug",0);
	if (ob->query_condition("snake_poison"))
		ob->clear_condition("snake_poison",0);
//	if (ob->query_condition("ss_poison"))
//		ob->clear_condition("ss_poison",0);
	if (ob->query_condition("wugong_poison"))
		ob->clear_condition("wugong_poison",0);
//	if (ob->query_condition("xx_poison"))
//		ob->clear_condition("xx_poison",0);
	if (ob->query_condition("xiezi_poison"))
		ob->clear_condition("xiezi_poison",0);
	if (ob->query_condition("zhizhu_poison"))
		ob->clear_condition("zhizhu_poison",0);
	if (ob->query_condition("zhua_poison"))
		ob->clear_condition("zhua_poison",0);
	if (ob->query_condition("ice_sting"))
		ob->clear_condition("ice_sting", 0);
	message_vision("大約一柱香過後，$N吐出一口紫血，青蛙慢慢地站了起來。\n",ob);
	command("say 你體內毒素已清，可以走啦。\n");
	return 1;
}