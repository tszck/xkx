// NPC snaker.c
// Last Modified by Winder on May. 15 2001
inherit NPC;
inherit F_DEALER;

#include <ansi.h>

void greeting(object ob);
void create()
{
	set_name("舞蛇人", ({ "snaker" }));
	set("long", "他是一個西域來的舞蛇人。\n");
	set("title", "西域蛇王");
	set("nickname", HIY "蛇見怕" NOR);
	set("gender", "男性");
	set("age", 33);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("no_get", 1);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);

	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("snake_count", 4);
	set("shenshe_count", 3);
	set("score", 10000);

	set("chat_chance",5);
	set("chat_msg", ({
		"舞蛇人吆喝道：停一停，看一看，有上好的蛇膽粉出售了￣\n",
		"舞蛇人把手腕劃出一道口子，又敷上蛇膽粉，咦，流血立即停止了。\n",
		"舞蛇人把手裏的蛇舞來舞去道：貨真價實的啦，別錯過好機會￣\n",
	}) );

	set("inquiry", ([
		"白駝山" : "我這裏的蛇膽粉就是用白駝山的蛇精心製作的。\n",
		"蛇膽粉" : "我的蛇膽粉能治各種外傷，療效不凡！\n",
	]));
	set("vendor_goods", ({
		"/d/baituo/obj/fen",
	}));

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
}

void init()
{
	object ob;

	::init();
	add_action("do_list","list");
	add_action("do_buy","buy"); 
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	object obn;
	if( !ob || environment(ob) != environment() ) return;
	if (((string)ob->query("family/family_name") == "白駝山派") &&
		(query("shenshe_count") > 0))
	{
		if(!present("shenshe",ob) && random(2)==1)
		{
			add("shenshe_count", -1);
			tell_object(ob, "這位"+RANK_D->query_respect(ob)+"，我這裏有「引路神蛇」，\n"+ "你先拿去用，不用擔心，我是真心幫你啦￣\n");
			obn=new("/d/baituo/obj/shenshe");
			obn->move(ob);
			return;
		}
	}
	say("舞蛇人殷勤地説：這位"+RANK_D->query_respect(ob)+"，買我的蛇膽粉吧，包您滿意。\n");
	return;
}

int accept_fight(object ob)
{
	object obn;
	if(query("snake_count") == 0)
	{
		message_vision("舞蛇人怒道：$N，你還想騙老子的蛇嗎？呸！！ \n",ob);
		return 1;
	}
	if(!objectp(present("mang she",environment(ob))))
	{
		add("snake_count", -1);
		message_vision("舞蛇人大叫一聲：$N，你小子竟敢跟老子過不去，嚐嚐蛇的厲害！\n", ob);
		obn=new("/d/baituo/npc/mangshe");
		obn->move(environment(ob));
		obn->kill_ob(ob);
		return 0;
	}
	message_vision("舞蛇人大怒道：讓你小子嚐嚐老子的厲害。\n", ob);
	return 1;
}

