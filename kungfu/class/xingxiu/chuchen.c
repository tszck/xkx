// shihou.c 出塵子

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("出塵子", ({ "chuchen zi", "chuchen", "zi" }));
	set("nickname", "星宿派八弟子");
	set("long", 
	"他身材雖矮，卻是腰粗膀闊，橫着看去，倒頗爲雄偉，動作也甚敏捷。
手中握的鋼杖又長又重。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);
	set("combat_exp", 100000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 4);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 50);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 70);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 70);
	set_skill("parry", 50);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("no_get",1);
	set("env/wimpy", 60);
	set("inquiry", ([
		"星宿派" : "可惜老仙不准我收徒, 否則你可拜我爲師。",
		"深澗"   : "問阿紫吧。",
		"吹捧"   : "小師妹最討老仙喜歡, 你去問她吧。",
		"蕭峯"   : "要不是那廝, 我早逮住了小師妹。",
		"老仙"   : "你得多吹捧老仙, 否則別想有出頭之日。\n",
		"丁春秋" : "丁春秋是你叫的嗎? 沒大沒小的。以後叫老仙! ",
		"星宿海" : "我現在很忙, 找別人帶你去吧。",
		"杖法"   : "論天山杖法, 我最拿手。", 
		"天山杖法" : "你先練練基本功吧。",
		"基本功" : "找個山壁練。",
		"山壁"   : "還嘮叨什麼? 自己去找。",
		"神王木鼎" : "我可沒提過, 再問我宰了你。",
		"山洞"   : "笨蛋, 把亂石推開不就可以進去了嗎? ",
		"鋼杖"   :    (: ask_me :),
	]) );
	set("zhang_count", 4);
	create_family("星宿派", 2, "弟子");
	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	this_object()->kill_ob(ob);
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";

	if ( present("gangzhang", this_player()) )
		return RANK_D->query_respect(this_player()) + "你現在身上不是有鋼杖嗎，怎麼又來要了？ 真是貪得無饜！";

	if (query("zhang_count") < 1) return "對不起，鋼杖已經發完了";
	ob = new("/clone/weapon/gangzhang");
	ob->move(this_player());
	add("zhang_count", -1);
	message_vision("$N獲得一根鋼杖。\n",this_player());
	return "記住，別丟掉了。";
}

void attempt_apprentice(object ob)
{
	command("say 老仙還沒允許我收徒呢。");
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();

	if (interactive(ob) && !environment(ob)->query("no_fight") &&
		((fam = ob->query("family")) && fam["family_name"] != "星宿派"))
	{
		command("say 大膽狂徒，竟敢闖到星宿海來偷寶！！！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}
