// xiaoyaozi.c 逍遙子
// Modified by Winder June.25 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("逍遙子", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("title", "逍遙派開山祖師");
	set("long", 
		"他就是逍遙派開山祖師、但是因為逍遙派屬於一個在江湖中\n"
		"的祕密教派，所以他在江湖中不是很多人知道，但其實他的\n"
		"功夫卻是。。。。他年滿七旬，滿臉紅光，鬚眉皆白。\n");
	set("gender", "男性");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);
	
	set("max_qi", 5500);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jingli", 2000);
	set("max_jingli", 2000);
	set("jiali", 100);
	set("combat_exp", 10000000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("beiming-shengong", 200);
	set_skill("dodge", 200);
	set_skill("lingboweibu", 300);
	set_skill("strike", 200);
	set_skill("liuyang-zhang", 300);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("ruyi-dao", 300);
	set_skill("zhemei-shou", 300);
	set_skill("hand", 200);
	set_skill("literate", 120);
	set_skill("luteplaying", 150);
	set_skill("goplaying", 150);
	set_skill("literate", 100);
	set_skill("painting", 150);
	set_skill("medicine", 150);
	set_skill("construction", 150);
	set_skill("horticulture", 150);
	set_skill("dramaturgy", 150);
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("逍遙派", 1, "開山祖師");
	set("class", "taoist");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 80) {
		command("say 我逍遙派內功的源泉來自於北冥神功的心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"的北冥神功是否還應該有所提高啊？");
		return;
	}

	if (ob->query_int() < 35) {
		command("say 我逍遙派武功最重視“逍遙”二字。");
		command("say 而何謂“逍遙”，這隻能靠你自己去領悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎還有待提高啊。");
		return;
	}
	command("smile");
	command("say 想不到在這世上竟然還有人可以繼承我的逍遙心法！");
	command("recruit " + ob->query("id"));
	ob->set("title","逍遙派護法使者");
}
