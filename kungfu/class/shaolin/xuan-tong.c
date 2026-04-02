// Npc: /kungfu/class/shaolin/xuan-tong.c
// Date: YZC 96/01/19
// last modified 01/5/5

inherit NPC;

string ask_me();

void create()
{
	set_name("玄痛大師", ({
		"xuantong dashi",
		"xuantong",
		"dashi",
	}));
	set("long",
		"他是一位白鬚白眉的老僧，身穿一襲銀絲棕黃袈裟。他身材高大，\n"
		"兩手過膝。雙目半睜半閉，卻不時射出一縷精光。\n"
	);


	set("nickname", "戒律院主持");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

        set("inquiry", ([
                  "少林派"   : "我少林正宗天下第一 \n",
                  "祕籍"     : (: ask_me :),
                  "棍法通解"  : (: ask_me :),
                  "shu" : (: ask_me :),
                       ]));

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);
	set("book_count",1);

	set_skill("force", 140);
	set_skill("hunyuan-yiqi", 140);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 210);
	set_skill("parry", 140);
	set_skill("hand", 140);
	set_skill("claw", 140);
	set_skill("club", 140);
	set_skill("staff", 140);
	set_skill("zui-gun", 210);
	set_skill("pudu-zhang", 210);
	set_skill("qianye-shou", 210);
	set_skill("yingzhua-gong", 210);
	set_skill("buddhism", 140);
	set_skill("literate", 140);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "yingzhua-gong");
	map_skill("staff", "pudu-zhang");
	map_skill("club", "zui-gun");
	map_skill("parry", "yingzhua-gong");

	prepare_skill("finger", "nianhua-zhi");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("少林派", 36, "弟子");

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me;
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "與本派素無來往，不知此話從何談起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺內學藝。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，貧僧哪裏敢當 !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..0] == "澄")
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麼跑到我這兒來了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say " + RANK_D->query_respect(ob) + "，你輩份不合，不能越級拜師。");
		return;
	}

	return;
}

string ask_me()
{
	object ob;

	if (this_player()->query("family/master_id")!="xuantong dashi")
		return RANK_D->query_respect(this_player()) +
		"非我弟子，不知此話從何談起？";
	if (query("book_count") < 1)
		return "你來晚了，本派的祕籍不在此處。";
	add("book_count", -1);
	ob = new("/clone/book/club");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到棍法通解啦。\n");
	return "好吧，這本「棍法通解」你拿回去好好鑽研，光大我少林武學。";
}
