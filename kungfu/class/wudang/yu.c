// yu.c 俞蓮舟

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("俞蓮舟", ({ "yu lianzhou", "yu" }));
	set("nickname", "武當二俠");
	set("long","他就是張三豐的二弟子俞蓮舟。\n他今年五十歲，身材魁梧，氣度凝重。\n雖在武當七俠中排名第二，功夫卻是最精。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 80000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 110);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 150);
	set_skill("liangyi-jian", 80);
	set_skill("wudang-jian", 80);
	set_skill("wudang-quan", 80);
	set_skill("taoism", 80);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
	set("env/wimpy", 60);
        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("武當派", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "武當派" )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "並非我門中人，習武還是先從各位道長起吧！");
		return;
	}
        if ((int)ob->query_skill("taiji-shengong", 1) < 60)
	{
                command("say 我武當派乃內家武功，最重視內功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否還應該在太極神功上多下點功夫？");
                return;
        }
	if ((int)ob->query("shen") < 80000)
	{
		command("say 我武當乃是堂堂名門正派，對弟子要求極嚴。");
		command("say " + RANK_D->query_respect(ob) + "若能做出" +
			"幾件俠義之事，我一定收你。");
		return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我輩中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
}
