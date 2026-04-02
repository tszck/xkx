// banshuxian.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("班淑嫺", ({ "ban shuxian", "ban" }));
	set("title", "崑崙派掌門夫人");
	set("long",
"這是一個身材高大的半老女子，頭髮花白，雙目含威，眉心間聚
有煞氣。她就是崑崙派掌門、名揚江湖的鐵琴先生何太沖的夫人。
班淑嫺是崑崙派的“太上掌門”，連何太沖也忌她三分，數十年
來在崑崙山下頤指氣使慣了，數百里方圓之內，儼然女王一般。\n");
	set("gender", "女性");
	set("class", "swordman");
	set("age", 44);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("per", 20);
	set("str", 26);
	set("int", 24);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 40000);

	set_skill("literate", 120);
	set_skill("force", 155);
	set_skill("xuantian-wuji", 160);
	set_skill("dodge", 145);
	set_skill("taxue-wuhen", 225);
	set_skill("strike", 60);
	set_skill("kunlun-strike", 90);
	set_skill("parry", 160);
	set_skill("sword", 170);
	set_skill("leg", 140);
	set_skill("chuanyun-leg", 220);
	set_skill("liangyi-sword", 170);
	set_skill("xunlei-sword", 220);
	set_skill("mantian-huayu", 220);
	set_skill("throwing", 165);

	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("leg", "chuanyun-leg");
	map_skill("parry", "liangyi-sword");
	map_skill("sword", "liangyi-sword");
	prepare_skill("leg", "chuanyun-leg");
	set("inquiry",
	([
		"祕籍" : (: ask_me :),
	]));
	set("book_count", 1);
	set("env/wimpy", 60);
	create_family("崑崙派", 4, "掌門夫人");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao2")->wear();
}

void attempt_apprentice(object ob)
{
/*
	if((int)ob->query("shen")<0)
	{
		 command("say 我崑崙乃是堂堂名門正派，"+RANK_D->query_respect(ob)+"的品德實在令人懷疑。");
		command("say "+RANK_D->query_respect(ob)+"還是先回去做點善事吧。");
		return;
	}
*/
	if(ob->query("gender")=="男性")
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"你們這些臭男人我見了就煩，快給我走開！");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say 前輩怎敢開這等玩笑，真是折殺做晚輩的了。");
		return;
	}

	if(ob->query_skill("xuantian-wuji",1)<100)
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"你的玄天無極功太差，我可不想收你。");
		return;
	}
	command("say 好吧，以後你就跟我學武功吧，你須得安心學藝，不可亂來。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;
	ob = this_player();

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "崑崙派")
		return RANK_D->query_respect(this_player()) +
			"與本派素無來往，不知此話從何談起？";
	if(ob->query("gender")=="男性")
		return "給我走開，我看見你們這些臭男人就煩。";
	if (query("book_count") < 1)
		return "你來晚了，本派真經已被你師兄拿走了。";
	add("book_count", -1);
	ob = new("/clone/book/lyj-book.c");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到兩儀劍心得啦。\n");
	return "先師曾傳下來這本「兩儀劍心得」，你拿回去好好鑽研。";
}

