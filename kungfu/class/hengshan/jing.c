// Last Modified by Sir on May. 22 2001
// jing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <command.h>
#include "hengshan.h";
string ask_for_join();
string ask_yao();
void create()
{
	set_name("定靜師太", ({ "dingjing shitai", "shitai", "dingjing" }) );
	set("long", "她是恆山派的定靜師太，身穿道袍，眉目之間有一股祥和之氣。\n"
			"自然而然的有股威嚴。\n");
	set("gender", "女性");
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"join"  : (: ask_for_join :),
		"天香斷續膏" : (: ask_yao :),
		"還俗"  : "恆山弟子，不能還俗。",

	]));
	set("env/wimpy", 60);

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
	set("combat_exp", 1500000);
	set("score", 1000);
	set("yao_count", 1);

	set_skill("unarmed", 180);
	set_skill("sword", 200);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 150);
	set_skill("baiyun-xinfa",180);
	set_skill("hengshan-jian", 300);
	set_skill("chuanyun-shou",300);
	set_skill("tianchang-zhang",300);
	set_skill("lingxu-bu", 250);
	set_skill("literate", 100);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");

	create_family("恆山派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
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
		command( "say 你若能多爲俠義之舉，當能承我衣鉢。\n");
		return;
	}

	command("say 阿彌陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能努力行善，濟度衆生，以光大我恆山派。");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "儀" + name[1..1];
	command("say 從今以後你的法名叫做" + new_name + "。");
	ob->set("name", new_name);
}

string ask_yao()
{
	object ob;

	if (this_player()->query("family/master_id")!="dingjing shitai")
		return RANK_D->query_respect(this_player()) +
		"非我弟子，不知此話從何談起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你來晚了，天香斷續膏剛巧給人了。";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/tianxianggao");
	ob->move(this_player());
	return "好吧，這塊天香斷續膏就先給你吧。";
}
