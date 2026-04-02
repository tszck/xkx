// lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);
string ask_me();
string ask_huang();

void create()
{
	set_name("陸高軒", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("nickname",HIC "神機妙算" NOR);
	set("long","他四十來歲年紀，文士打扮，天庭飽滿，地闊方圓，容貌頗為英俊，神情和藹可親。然而滿面愁容，恰似頃刻間便有殺身之禍一般。\n" );
	set("gender", "男性");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
	set("qi",1500);
	set("max_jing",500);
	set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("dulong-dafa", 70);
	set_skill("dodge", 70);
	set_skill("yixingbu", 70);
	set_skill("hand", 70);
	set_skill("shenlong-bashi", 100);
	set_skill("parry", 70);
	set_skill("hook", 70);
	set_skill("ruyi-hook", 100);
	set_skill("literate", 70);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shenlong-bashi");
	map_skill("hook", "ruyi-hook");
	prepare_skill("hand", "shenlong-bashi");
	set("env/wimpy", 60);
	set("party/party_name", HIY"神龍教"NOR);
	set("party/rank", "軍師");
	set("party/level", 2);
	create_family("神龍教", 2, "弟子");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"洪安通" : "這三個字是你説的嗎？",
		"洪教主" : "洪教主仙福永享，壽與天齊，洪教主神目如電，燭照四方。",
		"蘇荃"   : "沒規沒矩的。",
		"神龍島" : "神龍島在汝州的東北方向，從塘沽口出海便到。",
		"神龍教" : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"教主"   : "教主脾氣不好，要討他歡心才好。\n",
		"口號"   : "萬年不老！永享仙福！壽與天齊！文武仁聖！\n",
		"祕籍"   : (: ask_me :),
		"book"   : (: ask_me :),
		"雄黃"   : (: ask_huang :),
		"huang"  : (: ask_huang :),
	]) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 10);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "神龍教" NOR ) {
		command("say 你不是本教教眾，想來找死啊！");
		return;
	}
	if ((int)ob->query_skill("literate",1) < 40 ) {
		command("say 你的學問太低了，還是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > -0 ) {
		command( "say 我神龍教與世隔絕，向來不與您這種白道人物打交道，您請回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "神龍教")
		return RANK_D->query_respect(this_player()) + "與本教素無來往，不知此話從何談起？";
	if (query("book_count") < 1)
		return "你來晚了，本教的祕籍不在此處。";
	add("book_count", -1);
	if (random(2) == 0) ob = new("/clone/book/shoufa");
	else ob = new("/clone/book/bufa");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到"+ob->query("name")+"啦。\n");
	return "好吧，這本「"+ob->query("name")+"」你拿回去好好鑽研。";
}

string ask_huang()
{
	mapping fam; 
	object ob, me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "神龍教")
		return RANK_D->query_respect(me) + "與本教素無來往，不知此話從何談起？";
	if( present("xionghuang", me) )
		return RANK_D->query_respect(me)+"你現在身上不是雄黃嗎，怎麼又來要了？真是貪得無饜！";
	if( time() < me->query("huang/time") + 1800 )
		return RANK_D->query_respect(me) + "你不是剛要過雄黃，怎麼又來要了？過段時間再來吧。";

	me->set("huang/time", time()); 
	ob = new(VEGETABLE_DIR"xionghuang");
	ob->move(me);
	return "好吧，這雄黃你就拿去吧。";
}
#include "/kungfu/class/shenlong/shenlong.h"; 
