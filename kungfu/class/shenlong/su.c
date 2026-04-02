// su.c 蘇荃

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

int ask_tuijiao();
void create()
{
	set_name("蘇荃", ({ "su quan", "su" }));
	set("long","美貌少婦，看模樣不過二十三四歲年紀，微微一笑，媚態橫生，豔麗無比。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 400000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 150);
	set_skill("dodge", 180);
	set_skill("yixingbu", 250);
	set_skill("leg", 150);
	set_skill("strike", 180);
	set_skill("jueming-leg", 220);
	set_skill("huagu-mianzhang", 250);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("meiren-sanzhao", 220);
	set_skill("literate", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("leg", "jueming-leg");
	map_skill("parry", "meiren-sanzhao");
	map_skill("sword", "meiren-sanzhao");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("leg", "jueming-leg");
	set("party/party_name", HIY"神龍教"NOR);
	set("party/rank", HIR"教主夫人"NOR );
	set("party/level", 3);
	create_family("神龍教", 2, "弟子");

	set("inquiry", ([
		"洪安通" : "這三個字是你説的嗎？",
		"洪教主" : "洪教主仙福永享，壽與天齊，洪教主神目如電，燭照四方。",
		"蘇荃"   : "沒規沒矩的。",
		"神龍島" : "神龍島在汝州的東北方向，從塘沽口出海便到。",
		"神龍教" : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"教主"   : "教主脾氣不好，要討他歡心才好。\n",
		"口號"   : "萬年不老！永享仙福！壽與天齊！文武仁聖！\n",
		"入教"   : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"退教"   : (: ask_tuijiao :),
		"rujiao" : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"tuijiao": (: ask_tuijiao :),
	]));
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 憑你這點能耐，也敢在老孃頭上動土？\n") :),
		(: command("say 你活得不耐煩了找死啊？\n") :),		
		(: perform_action, "strike.hua" :),
		(: perform_action, "strike.baigu" :),
		(: perform_action, "sword.fengzi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
       
	setup();
	carry_object("/d/shenlong/npc/obj/ycloth")->wear();
	carry_object(__DIR__"obj/duanjian")->wield();
	add_money("silver", 50);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))	  
		{
			set("combat_exp",500000);
			set("qi",10);
			set("jing",10);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "神龍教" NOR ) {
		command("say 你不是本教教眾，想來找死啊！");
		return;
	}
	if ((int)ob->query_skill("dulong-dafa",1) < 60 ) {
		command("say 你的本門內功心法太低了，還是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > -10000  ) {
	command("say 我神龍教與世隔絕，向來不與您這種白道人物打交道，您請回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}

int ask_tuijiao()
{
	object ob;
	ob=this_player();

	if(ob->query("party/party_name") != HIY "神龍教" NOR )
	{
	message_vision("蘇荃莞爾一笑，對$N説道：你還沒加入我神龍教呢，就想退教？\n",ob);
		return 1;
	}
	if(ob->query("family/family_name") == "神龍教" )
	{
		message_vision("蘇荃板起俏臉對$N説道：你已經是我神龍弟子，如何能退教？\n", ob);
		return 1;
	}
	command("look "+ob->query("id"));
	command("sigh ");
	command("nod ");
	command("say 異日你不要撞在我手上！");
	ob->delete("party");
	ob->delete("rank");
	ob->delete("level");
	return 1;
}

