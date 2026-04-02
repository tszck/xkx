#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void consider();
string ask_me();
string ask_yao();
string ask_gua();

void create()
{
	object ob;
	set_name("黃藥師", ({"huang yaoshi", "huang", "yaoshi"}));
	set("title", "桃花島主");
	set("nickname", HIY "東邪" NOR );
	set("gender", "男性");
	set("age", 42);
	set("long", 
		"他就是桃花島主。行事好惡全由己心，因此被人稱作「東邪」。\n");
	set("attitude", "peaceful");
	set("class", "scholar");
	
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"黃藥師嘆了口氣道：“唉 …… 蓉兒這苦命的孩子，從小就沒了娘 ……”\n",
		"黃藥師低頭沉思，悠然不語。\n",
	}));
	set("inquiry", ([
		"黃蓉"         : "你敢直稱我女兒的閨名？ \n",
		"九陰真經"     : "如果你能幫我取得真經上冊，我一定重重謝你。\n",
		"九花玉露丸"   : "此丸配製不易，乘風那裏可能還有吧。\n",
		"無常丹"       : (: ask_yao :),
		"鐵八卦"       : (: ask_gua :),
		"祕籍"         : (: ask_me :),
		"旋風掃葉腿法" : (: ask_me :),
	]));

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 3000);
	set("max_jing", 3000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 100);

	set("book_count", 1);
	set("yao_count", 1);
	set("gua_count", 1);
	set("combat_exp", 3000000);
	set("score", 0);
	 
	set_skill("force", 200);		// 基本內功
	set_skill("bibo-shengong", 200);	// 碧波神功
	set_skill("claw", 200);			// 基本爪法
	set_skill("hand", 200);			// 基本手法
	set_skill("finger", 200);		// 基本指法
	set_skill("tanzhi-shentong", 300);	// 彈指神通
	set_skill("unarmed", 200);		// 基本拳腳
	set_skill("strike", 200);		// 基本拳腳
	set_skill("luoying-zhang", 300);	// 落英神劍掌
	set_skill("xuanfeng-leg", 300);		// 旋風掃葉腿
	set_skill("dodge", 200);		// 基本躲閃
	set_skill("anying-fuxiang", 300);	// 暗影浮香
	set_skill("parry", 200);		// 基本招架
	set_skill("sword", 200);		// 基本劍法
	set_skill("luoying-shenjian", 300);	// 落英神劍
	set_skill("yuxiao-jian", 300);		// 玉簫劍法
	set_skill("lanhua-shou", 300);		// 蘭花拂穴手
	set_skill("qimen-wuxing",150);		// 奇門五行
	set_skill("array", 120);		// 基本陣法
	set_skill("count",150);			// 陰陽八卦
	set_skill("literate",150);		// 讀書識字
	
	map_skill("force"  , "bibo-shengong");
	map_skill("finger" , "tanzhi-shentong");
	map_skill("hand"   , "lanhua-shou");
	map_skill("strike", "luoying-zhang");
	map_skill("unarmed" , "xuanfeng-leg");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "luoying-shenjian");
	map_skill("sword"  , "yuxiao-jian");
	prepare_skill("hand", "lanhua-shou");
	prepare_skill("finger", "tanzhi-shentong");
	
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.tianwai" :),
		(: perform_action, "finger.jinglei" :),
		(: perform_action, "hand.fuxue" :),
		(: exert_function, "roar" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("桃花島", 1, "島主");
	setup();
	
	carry_object(__DIR__"obj/yuxiao")->wield();
	carry_object(__DIR__"obj/bupao")->wear();
//	carry_object("clone/book/jiuyin2");
  if (clonep())
  {
		ob = new("/clone/book/jiuyin2");
		if (ob->violate_unique())	destruct(ob);
		else ob->move(this_object());
	}
}

void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if (ob->query("class") == "eunach" ||
		ob->query("class") == "bonze" ||
		ob->query("class") == "lama")
	{
		command("say 我平生最討厭就是不三不四希奇古怪的人了！");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 我不收資質差的弟子，您請回吧！");
		return;
	}
	if ((int)ob->query_skill("bibo-shengong",1) < 50 )
	{
		command("say 你的本門內功心法太低了，還是努努力先提高一下吧!");
		return;
	}
	if ((int)ob->query("shen") >100000 ||
		(int)ob->query ("shen") < -100000 )
	{
		command("say 我桃花島與世隔絕，向來不與您這種成名人物打交道，您請回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] == "桃花島") return 1 ;
	if ((int)ob->query_temp("tmark/黃") == 1 )
		message_vision("黃藥師看了看$N，說道：咱們現在是誰也不欠誰，\n你不要再找我學習技藝了。\n", ob);
	if (!(int)ob->query_temp("tmark/黃")) return 0; 
	ob->add_temp("tmark/黃", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" )
	{
 		if (!(int)who->query_temp("tmark/黃"))
			who->set_temp("tmark/黃", 0);
		message_vision("黃藥師看了看$N送來的祕籍，點了點頭，說道：\n難得你將真經送回。你送的東西我就收下了。\n作爲補償,你可以從我這裏學點功夫。\n",who);
		who->add_temp("tmark/黃", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob, me = this_player();
	
	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"非我弟子，不知此話從何談起？";
	if (query("book_count") < 1) return "你來晚了，本派的祕籍不在此處。";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(me);
	command("rumor "+me->query("name")+"拿到旋風掃葉腿法啦。\n");
	return "好吧，這本「旋風掃葉腿法」你拿回去好好鑽研。";
}
string ask_yao()
{
	object ob, me = this_player();

	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"非我弟子，不知此話從何談起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你來晚了，無常丹剛巧給人了。";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/wuchangdan");
	ob->move(me);
	return "好吧，這丸無常丹就先給你吧。";
}
string ask_gua()
{
	object ob, me = this_player();
	
	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"非我弟子，不知此話從何談起？";
	if (query("gua_count") < 1 || random(3) > 0)
		return "你來晚了，鐵八卦剛巧給人了。";
	if (me->query_skill("count", 1) < 30 ||
		me->query_skill("bibo-shengong", 1) < 30)
		return "鐵八卦你拿着也沒什麼用，還是留給別人了。";
	add("gua_count", -1);
	ob = new(__DIR__"obj/bagua");
	ob->move(me);
	return "好吧，這枚鐵八卦就先給你吧。";
}
