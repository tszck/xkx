// Last Modified by Sir on May. 22 2001
// xian.c
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <command.h>
#include <ansi.h>
string ask_for_join();
string ask_me();
string ask_yao();
void create()
{
	set_name("定閒師太", ({ "dingxian shitai", "shitai", "dingxian" }) );
	set("long", "她就是恆山派的定閒師太，她身材瘦高，慈眉善目，\n"
		"是現任恆山派掌門人。\n");
	set("gender", "女性");
	set("title", HIB"恆山派第十三代掌門"NOR);
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"剃度"  : "貧尼不剃度弟子。",
		"出家"  : "貧尼不剃度弟子。",
		"還俗"  : "恆山弟子，不能還俗。",
		"白雲熊膽丸" : (: ask_yao :),
		"祕籍"	 : (: ask_me :),
		"天長掌法譜" : (: ask_me :),
	]));
	set("no_get",1);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield chacngjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
	}));


	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 3000000);
	set("score", 1000);
	set("book_count", 1);
	set("yao_count", 1);

	set_skill("unarmed", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 150);
	set_skill("baiyun-xinfa",200);
	set_skill("hengshan-jian", 300);
	set_skill("chuanyun-shou",300);
	set_skill("tianchang-zhang",300);
	set_skill("lingxu-bu", 300);
	set_skill("literate", 150);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");

	prepare_skill("hand", "chuanyun-shou");
	prepare_skill("strike", "tianchang-zhang");

	create_family("恆山派", 13, "掌門");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say 阿彌陀佛！貧尼不收俗家弟子。");
		return;
	}

	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say 你的本門內功心法火候不足,難以領略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen")<100000)
	{
		command( "say 你若能多為俠義之舉，當能承我衣缽。\n");
		return;
	}
	command("say 阿彌陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能努力行善，濟度眾生，以光大我恆山派。");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "儀" + name[1..1];
	command("say 從今以後你的法名叫做" + new_name + "。");
	ob->set("name", new_name);
}


string ask_me()
{
	object ob;

	if (this_player()->query("family/family_name")!="恆山派")
		return RANK_D->query_respect(this_player()) +
		"與本派毫無瓜葛，我派的武功典籍可不能交給你。";
	if (query("book_count") < 1)
		return "你來晚了，本派的祕籍不在此處。";
	add("book_count", -1);
	ob = new("/clone/book/tianchang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到天長掌法譜啦。\n");
	return "好吧，這本「天長掌法譜」你拿回去好好鑽研。";
}
string ask_yao()
{
	object ob;

	if (this_player()->query("family/master_id")!="dingxian shitai")
		return RANK_D->query_respect(this_player()) +
		"非我弟子，不知此話從何談起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你來晚了，白雲熊膽丸剛巧給人了。";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/baiyunwan");
	ob->move(this_player());
	return "好吧，這粒白雲熊膽丸就先給你吧。";
}
