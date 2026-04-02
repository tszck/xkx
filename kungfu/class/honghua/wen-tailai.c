// wen-tailai.c 文泰來
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("文泰來", ({ "wen tailai", "wen", "tailai" }));
	set("title", HIR"紅花會"HIG"四當家"NOR);
	set("nickname", HIM"奔雷手"NOR);
	set("long","他是紅花會的四當家，身穿一件青色長衫。\n他年紀好像在三十上下，身材十分槐梧，雙手青筋突出，佈滿了老繭。十五歲起浪蕩江湖，手掌下不知擊斃過多少神奸巨憝、兇徒惡霸。\n");
	set("gender", "男性");
	set("class", "swordman");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2000);
	set("max_jing", 1500);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
	set("combat_exp",800000);
	set("score", 100000);

	set_skill("force", 100);
	set_skill("honghua-shengong", 100);
	set_skill("dodge", 100);
	set_skill("youlong-shenfa", 150);
	set_skill("hand", 100);
	set_skill("benlei-shou", 250);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("qiuge-dao", 150);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "qiuge-dao");
	map_skill("blade", "qiuge-dao");
	prepare_skill("hand", "benlei-shou");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("紅花會", 2, "弟子");
	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="wen tailai")
	{
		command( "chat "+ob->query("name")+"！你這等邪惡奸詐之徒，我豈能仍是你的師父。\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","紅花會" + RED + "棄徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000)
	{
		command("say 我紅花會收徒極嚴。");
		command("say 這位" + RANK_D->query_respect(ob) + "平時還要多做一些行俠仗義之事！");
		return;
	}
	command("say 好，你這個年青人還不錯，我收下你了！");
	command("recruit " + ob->query("id"));
}

