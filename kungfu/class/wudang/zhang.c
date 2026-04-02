// zhang.c 張三豐

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();
string ask_zhenwu();

void create()
{
	object ob;
	set_name("張三豐", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", 
"他就是武當派開山鼻祖、當今武林的泰山北斗，中華武功承先啓
後、繼往開來的大宗師。他以自悟的拳理、道家沖虛圓通之道和
九陽真經中所載的內功相發明，創出了輝映後世、照耀千古的武
當一派武功。此後他北遊寶鳴，見到三峯挺秀，卓立雲海，於武
學又有所悟，乃自號三豐。
身穿一件污穢的灰色道袍，不修邊幅。身材高大，年滿百歲，滿
臉紅光，鬚眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
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
	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 300);
	set_skill("wudang-quan", 300);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	set("inquiry", ([
		"祕籍" : (: ask_me :),
		"真武劍" : (: ask_zhenwu : ),
	]));
	set("book_count", 1);
	create_family("武當派", 1, "開山祖師");
	set("class", "taoist");

	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/zhenwu-jian");
		if ( ob->violate_unique())
      destruct(ob);
    else
      {
      	ob->move(this_object());
      	ob->wield();
    	}      
	}
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}
void init()
{
	object ob;
	mapping myfam;

	::init();
	if (interactive(ob=this_player()) && ob->query("family"))
	{
		if (ob->query("family/master_id") == "zhang sanfeng" &&
			ob->query("shen") < -100 )
		{
			command("say "+RANK_D->query_rude(ob)+ "膽敢瞞着我在外胡作非爲！\n");
			command("expell " + ob->query("id"));
			add_action("do_qiecuo","qiecuo");
			return;
		}
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "武當派")&&(!ob->query_skill("taiji-shengong",1))&&(ob->query("combat_exp")>500000))
       		{
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + ob->query("id"));
        	}
	add_action("do_qiecuo","qiecuo");
	}
	
	add_action("do_qiecuo","qiecuo");
}

string ask_zhenwu()
{
	object player = this_player();

	if( !player->query("wudang/zhenwu") )
		return "「真武劍」是貧道早年時所用的兵刃。";
}
void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "武當派" )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "並非我門中人，習武還是先從各位道長起吧！");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 100) {
		command("say 我武當派乃內家武功，最重視內功心法。"); 
		command("say " + RANK_D->query_respect(ob) + "是否還應該在太極神功上多下點功夫？");
		return;
	}
	if ((int)ob->query_skill("taoism", 1) < 80)
	{
		command("say 我武當派乃道家武功，高深的武功離不開道學心法。");
		command("say " + RANK_D->query_respect(ob) + "是否還應該多讀讀道德經？");
		return;
	}
	if ((int)ob->query("shen") < 200000)
	{
		command( "say 學武之人，德義爲先，功夫的高低倒還在其次，未練武，要先學做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否還做得不夠？");
		return;
	}
	if (ob->query_int() < 30)
	{
		command( "say 我武當派武功全從道藏悟出。");
		command( "say 要能達到爐火純青之境，體質什麼的倒是無關緊要，悟性卻是半點也馬虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性還大有潛力可挖，還是請回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又覓得" + ob->name() + "這麼一個可塑之才，真是可喜可賀。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武當派")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if (query("book_count") < 1)
		return "你來晚了，本派的武功心法不在此處。";
	add("book_count", -1);
	ob = new("/clone/book/taiji-book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到太極拳經啦。\n");
	return "好吧，這本「太極拳經」你拿回去好好鑽研。";
}

