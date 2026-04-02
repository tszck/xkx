// azi.c 阿紫

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_azi();

void create()
{
//	set_name("阿紫", ({ "azi" }));
	set_name("阿紫", ({ "a zi","azi" }));
	set("nickname", "星宿派小師妹");
	set("long", 
		"一個身穿紫衣的美貌少女。她瓜子白淨臉，容顏俏麗，
可眼神中總是透出一股邪氣。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);

	set_skill("force", 40);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 30);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 30);
	set_skill("chousui-zhang", 40);
	set_skill("claw", 30);
	set_skill("sanyin-wugongzhao", 40);
	set_skill("parry", 20);
	set_skill("poison", 20);
	set_skill("staff", 20);
	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("env/wimpy", 60);

	set("inquiry", ([
		"星宿派" : "你想加入，就拜我爲師。",
		"深澗"   : "嘿嘿，哪有那麼容易就告訴你。",
		"星宿海" : "去星宿海幹什麼？拜我爲師就夠你學的了。",
		"丁春秋" : "丁春秋是你叫的嗎？沒大沒小的。以後叫老仙！",
		"老仙"   : "你得多吹捧老仙，否則別想有出頭之日。\n",
		"神王木鼎" : "我送了給我姐夫啦。有本事你自己去拿。",
		"姐夫"   : "連我姐夫蕭峯都不知道，你真是個大呆瓜。",
		"星宿"   : "你問的可是星宿派？",
		"吹捧"   : "女的容易多了，我最討老仙喜歡。男的得更加把勁。",
		"阿紫"   : "就是本姑娘我啊，你要怎麼樣？！\n",
		"神木王鼎" : (: ask_azi :),
	]));
	create_family("星宿派", 2, "弟子");
	setup();
	carry_object("/clone/medicine/nostrum/qingxinsan");
	carry_object("/d/xingxiu/obj/baihuqiu")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("shen") > 0)
	{
		command("say 你看上去真是個假正經，我纔不想收你呢。");
		return;
	}
	command("say 嘻嘻，我就收下你了吧。");
	command("recruit " + ob->query("id"));
}
string ask_azi()
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"與本派素無來往，不知此話從何談起？";
	if( this_player()->query_temp("smwd/step") )
	{
		this_player()->delete_temp("smwd/step", 1);
		ob=new(__DIR__"obj/ding");
		ob->move(this_object());
		command("fear");
		command("mapi "+this_player()->query("id"));
		return "師父他老人家的寶貝東西怎麼會在我這？！這位小"+RANK_D->query_close(this_player())+"一定搞錯了吧？";
	}
	else return "師父他老人家的寶貝東西怎麼會在我這？！";
}

