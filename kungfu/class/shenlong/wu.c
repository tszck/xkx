// wugeng.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("無根道長", ( { "wugen daozhang", "wugen","daozhang" }) );
	set("gender", "男性" );
	set("age", 55);
	set("long","這是個五十來歲的黑鬚道長，相貌威武，眼中略帶殺氣，臉上充滿了激憤之情。\n");

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

	set_skill("leg",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("literate", 80);
	set_skill("jueming-leg", 100);
	set_skill("yixingbu",120);
	set_skill("huashan-sword", 150);
	set_skill("dulong-dafa", 90);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("leg", "jueming-leg");
	map_skill("parry", "jueming-leg");
	map_skill("sword", "huashan-sword");
	prepare_skill("leg", "juming-leg");

	set("env/wimpy", 60);
	set("party/party_name", HIY"神龍教"NOR);
	set("party/rank", HIR"赤龍門"NOR"掌門使");
	set("party/level", 2);
	create_family("神龍教", 2, "弟子");

	set("inquiry", ([
		"洪安通" : "這三個字是你說的嗎？",
		"洪教主" : "洪教主仙福永享，壽與天齊，洪教主神目如電，燭照四方。",
		"蘇荃"   : "沒規沒矩的。",
		"神龍島" : "神龍島在汝州的東北方向，從塘沽口出海便到。",
		"神龍教" : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"教主"   : "教主脾氣不好，要討他歡心纔好。\n",
	]));
	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"daopao")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_join","join");
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))
		{
			set("combat_exp",100000);
			set("qi",100);
			set("jing",100);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒！");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
