// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("玄慈大師", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"他是一位白鬚白眉的老僧，身穿一襲金絲繡紅袈裟。\n"
		"他身材略顯佝僂，但卻滿面紅光，目蘊慈笑，顯得神完氣足。\n"
	);


	set("nickname", "少林寺方丈");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
/*
        set("chat_chance", 3);
        set("chat_msg", ({
"玄慈大師嘆了口氣道：“可惜我少林泱泱大派，而今如此人才凋落”\n",
"玄慈大師低頭自語道：“唉...我少林自渡西之後，再無可塑之才”\n",
"玄慈大師又嘆氣道：“本來澄藥也算是個曠世之奇才，只可惜塵緣未脫，歸隱於山林” \n",
        }) );
*/
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 110);
	set_skill("hunyuan-yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 160);
	set_skill("jingang-quan", 160);
	set_skill("unarmed", 110);
	set_skill("finger", 110);
	set_skill("strike", 110);
	set_skill("hand", 110);
	set_skill("claw", 110);
	set_skill("parry", 110);
	set_skill("nianhua-zhi", 160);
	set_skill("sanhua-zhang", 160);
	set_skill("fengyun-shou", 160);
	set_skill("longzhua-gong", 160);
	set_skill("buddhism", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("unarmed", "jingang-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("少林派", 36, "弟子");

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	object me;
	mapping ob_fam, my_fam;
 string name;

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