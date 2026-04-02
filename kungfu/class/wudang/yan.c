// yan.c 俞岱巖

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_yao1();
string ask_yao2();

void create()
{
	set_name("俞岱巖", ({ "yu daiyan", "yu" }));
	set("nickname", "武當三俠");
	set("long","他就是張三豐的弟子、武當七俠之三的俞岱巖。\n身穿一件乾乾淨淨的青布長衫。\n他不過三十出頭年紀，雙腿殘廢，張真人命他主持真武劍陣。\n");
	set("gender", "男性");
	set("age", 31);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("no_get", "1");
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 50);
	set_skill("tiyunzong", 70);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("taiji-jian", 150);
	set_skill("wudang-quan", 100);
	set_skill("wudang-jian", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
		"延年聚精丹" : (: ask_yao1 :),
		"九轉結氣丸" : (: ask_yao2 :),
	]));
	set("yao1_count", 1);
	set("yao2_count", 1);
	create_family("武當派", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",2 , ob);
	}
}

void greeting(object ob)
{
	int i;
	if (((int)ob->query_skill("taiji-shengong", 1) == 0))
	{
		message_vision( CYN"十三弟子對$N齊聲喝道：你這個邪魔外道，敢來真武劍陣？\n\n"NOR,ob);
		ob->set("qi",30);
		if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
		else ob->add("combat_exp",0);
		message_vision( CYN"真武劍陣頓時啓動，高臺上劍氣縱橫，把$N圍在中央。\n"NOR,ob);
		message_vision( CYN"十三口長劍齊出，在$N身上劃出了十三道口子，鮮血淋漓。\n"NOR,ob);
		message_vision("俞岱巖居高臨下，起手一掌把$N劈落高臺。\n\n\n"NOR,ob);
		ob->move("/d/wudang/nanyangong");
	}
}

void attempt_apprentice(object me)
{
	command("say " + RANK_D->query_respect(me) + "，我是個廢人了，怎麼能收徒呢？");
	return;
}

string ask_yao1()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武當派")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if (ob = present("jujing dan", this_player()))
		return "你身上不是帶着本門延年聚精丹？！";
	if (query("yao1_count") < 1)
		return "你來晚了，本門延年聚精丹已盡數給了本派弟子。";
	add("yao1_count", -1);
	ob = new("/clone/medicine/nostrum/jujingdan");
	ob->move(this_player());
	return "我這裏有本門延年聚精丹，你拿去吧。";
}

string ask_yao2()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武當派")
		return RANK_D->query_respect(this_player()) +
		"與本派素無來往，不知此話從何談起？";
	if (ob = present("jieqi wan", this_player()))
		return "你身上不是帶着本門九轉結氣丸？！";
	if (query("yao2_count") < 1)
		return "你來晚了，本門九轉結氣丸已盡數給了本派弟子。";
	add("yao2_count", -1);
	ob = new("/clone/medicine/nostrum/jieqiwan");
	ob->move(this_player());
	return "我這裏有本門九轉結氣丸，你拿去吧。";
}

