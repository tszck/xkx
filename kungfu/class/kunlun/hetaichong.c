// hetaichong.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();
string ask_ding();
string ask_su();

void create()
{
	set_name("何太沖", ({ "he taichong", "he" }));
	set("nickname", "鐵琴先生");
	set("long",
		"他就是崑崙派掌門、名揚江湖的鐵琴先生何太沖。\n"
		"雖然年紀已大，但仍然看得出他年輕時英俊瀟灑。\n");
	set("gender", "男性");
	set("class", "taoist");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 40000);

	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("xuantian-wuji", 160);
	set_skill("dodge", 140);
	set_skill("taxue-wuhen", 220);
	set_skill("strike", 80);
	set_skill("kunlun-strike", 120);
	set_skill("parry", 165);
	set_skill("sword", 175);
	set_skill("liangyi-sword", 175);
	set_skill("xunlei-sword", 220);
	set_skill("mantian-huayu", 220);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-cuff", 160);
  set_skill("leg", 155);
	set_skill("chuanyun-leg", 160);

	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-cuff");
	map_skill("parry", "xunlei-sword");
	map_skill("sword", "xunlei-sword");
	map_skill("leg", "chuanyun-leg");
	prepare_skill("cuff", "zhentian-cuff");
	prepare_skill("leg", "chuanyun-leg");
	
	set("no_get",1);

	create_family("崑崙派", 4, "掌門人");
	set("class", "taoist");

	set("inquiry",
	([
		"心法" : (: ask_me :),
		"蘇習之" : (: ask_su :),
		"追殺" : (: ask_ding :),
	]));

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao2")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
/*
	if((int)ob->query("shen")<0)
	{
		command("say 我崑崙乃是堂堂名門正派，"+RANK_D->query_respect(ob)+ "的品德實在令人懷疑。");
		command("say "+RANK_D->query_respect(ob)+
			"還是先回去做點善事吧。");
		return;
	}
*/
	if(ob->query("gender")=="女性")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"老夫可不敢收女弟子，你去找我夫人去吧。");
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
	command("say 好吧，我便收下你，只是你投入我門下之後，須得安心學藝。");
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
	if (query("book_count") < 1)
		return "你來晚了，本派心經已被你師兄拿走了。";
//     	if(ob->query("gender")=="男性"||ob->query("per")<23)
//		return "本派心經不在我這裏。";
	add("book_count", -1);
	ob = new("/clone/book/force-book2");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到崑崙心法啦。\n");
	return "我這裏有本「心法」，是有關吐吶吸氣的，你拿回去好好鑽研，有空多來找我哦！";
}

string ask_ding()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "崑崙派")
		return RANK_D->query_respect(this_player()) +
			"與本派素無來往，不知此話從何談起？";
		
	if(this_player()->query_skill("mantian-huayu",1) < 60)
		return "你如此自願為師門效力，不枉我平時一番栽培，速速去吧！";

	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
			"你現在身上不是有嗎，怎麼又來要了？";
	if (query("ding_count") < 1)
		return "喪門釘已給了我派去追殺蘇習之的人，你就不用去了。";
	add("ding_count", -1);
	this_player()->set_temp("kunlun/ding",1);
	ob = new("/d/kunlun/obj/sangmending");
	ob->move(this_player());
	return "你如此自願為師門效力，不枉我平時一番栽培，這把喪門釘你就拿去吧。";
}
string ask_su()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "崑崙派")
		return RANK_D->query_respect(this_player()) +
			"與本派素無來往，不知此話從何談起？";
		
	if(this_player()->query_temp("kunlun/ding",1))
		return "你還待在這裏做什麼，還不快去追蘇習之！";
	return "蘇習之這傢伙竟然敢偷看本派的兩儀神劍，我派弟子必當將其追殺。";
}
