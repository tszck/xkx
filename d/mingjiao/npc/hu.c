// hu.c 胡青牛
#include <ansi.h>
inherit NPC;

int ask_me();
int ask_book();
int ask_heal();
int ask_poison();

void create()
{
	set_name("胡青牛", ({ "hu qingniu", "hu" }));
	set("long", 
		"他就是明教號稱見死不救的胡青牛，據説他精通醫理，可以起死回\n"
                "生。但他從不醫教外人士。\n");
	set("gender", "男性");
	set("nickname","蝶谷醫仙");
	set("age", 50);
	set("no_get", "1");
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("inquiry", ([
		"療傷" : (:ask_me:),
		"治病"	: (: ask_heal :),
		"解毒"	: (: ask_poison :),
		"jing" : (:ask_book:),
		"醫書" : (:ask_book:),
		"醫經" : (:ask_book:),
		"胡青牛醫經" : "我的胡青牛醫經已經給張無忌拿去了。",
	]) );

	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 80000);

	set("count", 30);
	set("bookcount", 1);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed",90);
	set_skill("medicine",150);
	set_skill("parry", 90);

	set("party/party_name",HIG"明教"NOR);
	set("party/rank","教眾"NOR);
	create_family("明教", 35, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	object ob = this_player();
	object me = this_object();
	object where;
	
	if(me->is_fighting() || me->query_temp("busy"))
	{
		command("say 我現在沒空！");
		return 1;
	}
	
	if(me->query("count") < 1)
	{
		command("say 傷藥都用完了，我還沒來得及配，你一會再來吧。");
		return 1;
	}
	
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")
	 && (int)ob->query("eff_jing") == (int)ob->query("max_jing"))
	{
		command("? "+ob->query("id"));     
		command("say 你沒有受任何傷啊？");
		return 1;
	}
	if(ob->query("score")<500&&ob->query("combat_exp")>100500)
	{       
		command("say 你這點江湖閲歷，也想讓我為你療傷？");
		return 1;
	}	
	else
	{
		message_vision("胡青牛喂$N服下一顆藥丸，然後盤膝坐下，雙掌貼着$N的背心。\n", ob);
		if (ob->query("combat_exp")>100500)
		{
		if (ob->query("family/family_name") != "明教")
	            ob->add("score",-300);
	        else ob->add("score",-100);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{  where = environment(me);
		   where->add("no_fight", 1);
		   remove_call_out("newyao");
		   call_out("newyao",600,me);
		 }
		return 1;
	}
}

int recover(object ob)
{
	this_object()->delete_temp("busy");
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("大約過了一盅茶的時分，胡青牛慢慢地站了起來。\n",ob);
	command("say 你的傷勢已經全好了,可以走啦。");
	return 1;
}
int newyao(object me)
{
	object where = environment(me);
	this_object()->delete_temp("busy");
	me->add("count",30);
	where->add("no_fight", -1);
	return 1;
}
int ask_heal()
{
	object ob = this_player();
	object me = this_object();
 

        if(me->is_fighting()|| me->query_temp("busy"))
         {
           command("say 我現在沒空！");
           return 1;
         }

	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{       
		command("say 你這點江湖閲歷，也想讓我為你治病？");
		return 1;
	}
		
	if( ob->query_condition("ill_kesou")
	    || ob->query_condition("ill_zhongshu")
	    ||ob->query_condition("ill_shanghan")
	    ||ob->query_condition("ill_dongshang")
	    ||ob->query_condition("ill_fashao"))
	{
		message_vision("胡青牛輕釦$N脈門，略一思索，隨後轉身從藥簍裏取出幾味草藥，開始為$N熬藥。\n", ob);
		if( ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "明教")
	            ob->add("score",-300);
	        else ob->add("score",-100);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);		
		return 1;
	}
	
	else
	{
		command("? "+ob->query("id"));
		command("say 看你的氣色，並沒有生病啊？");
		return 1;
	}
	
}
int recover_II(object ob)
{
	this_object()->delete_temp("busy");
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
	message_vision("大約一柱香過後，胡青牛讓你喝下一碗剛熬好的熱氣騰騰的中藥。\n",ob);
	command("say 你的身體已無大礙,可以走啦。");
	return 1;
}

	
int ask_poison()
{
	object ob = this_player();
	object me = this_object();
 

        if(me->is_fighting()|| me->query_temp("busy"))
         {
           command("say 我現在沒空！");
           return 1;
         }
	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{       
		command("say 你這點江湖閲歷，也想讓我為你解毒？");
		return 1;
	}
		
	if( ob->query_condition("chanchu_poison")
	    || ob->query_condition("drunk")
	    ||ob->query_condition("flower_poison")
	    ||ob->query_condition("ice_poison")
	    ||ob->query_condition("iceshock")
	    || ob->query_condition("rose_poison")
	    ||ob->query_condition("scorpion_poison")
	    ||ob->query_condition("slumber_drug")
	    || ob->query_condition("snake_poison")
//	    ||ob->query_condition("ss_poison")
	    ||ob->query_condition("wugong_poison")
//	    || ob->query_condition("xx_poison")
	    ||ob->query_condition("xiezi_poison")
	    ||ob->query_condition("zhizhu_poison")
	    || ob->query_condition("zhua_poison")
	    ||ob->query_condition("ice_sting"))
	{
		message_vision("胡青牛輕釦$N脈門，雙眉深鎖，隨後喂$N服下一顆藥丸，盤膝坐下，雙掌貼着$N的背心，開始為$N解毒。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "明教")
	            ob->add("score",-400);
	        else ob->add("score",-200);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);		
		return 1;
	}
	
	else
	{
		command("? "+ob->query("id"));
		command("say 看來我幫不了你什麼忙了！");
		return 1;
	}
	
}
int recover_III(object ob)
{
	this_object()->delete_temp("busy");
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
	message_vision("大約一柱香過後，$N吐出一口紫血，胡青牛慢慢地站了起來。\n",ob);
	command("say 你體內毒素已清,可以走啦。");
	return 1;
}
string ask_book()
{
  
	object ob;
	
	if (query("bookcount") < 1)
		return "你來晚了，我的醫經給別人借去了。";
	add("bookcount", -1);
	switch (random(4))
	{
		case 0 : ob = new("/clone/book/medicine1"); break;
		case 1 : ob = new("/clone/book/medicine2"); break;
		case 2 : ob = new("/clone/book/medicine3"); break;
		case 3 : ob = new("/clone/book/medicine4"); break;
	}
	ob->move(this_player());
	return "好吧，這本醫經你拿回去好好鑽研。";
}