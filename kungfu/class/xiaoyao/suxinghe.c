// suxinghe.c 蘇星河
// Modified by Winder June.25 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_me();
string ask_book();

void create()
{
	set_name("蘇星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聰辯老人");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"此人就是號稱聰辯老人的蘇星河，據說他能言善辯， \n"
"是一個武林中的智者，而他的武功也是無人能知。\n");

	set("combat_exp", 3000000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"祕密地道" :(:ask_me:),
		"祕籍"     :(:ask_book:),
	]) );

	set("max_qi", 3400);
	set("max_jing", 400);
	set("neili", 3500);
	set("max_neili",3500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("dodge", 150);
	set_skill("hand", 150);
	set_skill("strike", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
        set_skill("force", 150);
	set_skill("lingboweibu", 220);
	set_skill("beiming-shengong", 150);
	set_skill("ruyi-dao", 220);
	set_skill("liuyang-zhang", 220);
	set_skill("zhemei-shou", 220);
	set_skill("literate", 100);
	set_skill("luteplaying", 150);
	set_skill("goplaying", 150);
	set_skill("literate", 100);
	set_skill("painting", 150);
	set_skill("medicine", 150);
	set_skill("construction", 150);
	set_skill("horticulture", 150);
	set_skill("dramaturgy", 150);
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("parry", "ruyi-dao");
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

	create_family("逍遙派", 2, "掌門");
	set("title","逍遙派第二代大弟子");
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

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否還應該在學問上多下點功夫？");
		return;
	}

	command("say 好吧，我就收下你了，今後要多加努力啊！");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
 object ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遙派")
	{
		return"想要祕籍就得加入逍遙派。";
	}
	command("sigh");
	return"本派的武功祕籍藏在一個很祕密的地方，我也沒去過。";
}
string ask_me()
{
 object ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遙派")
	{
		return"想要知道密道就得加入逍遙派。";
	}
	command("sigh");
	return"本派的密道在雲南無量山之上，很是艱險。你有興趣可以去看看。";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
}