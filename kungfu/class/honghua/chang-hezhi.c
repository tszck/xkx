// Last Modified by winder on Sep. 12 2001
// chang-hezhi.c 常赫志

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("常赫志", ({ "chang hezhi", "chang", "hezhi" }));
	set("title", HIR"紅花會"HIG"五當家"NOR);
	set("nickname", HIB"黑無常"NOR);
	set("long", 
"他身材又高又瘦，臉色蠟黃，眼睛凹進，眼角上有一粒黑痣，眉毛
斜斜的倒垂下來，形相甚是可怖。他是青城派慧侶道人的徒弟。黑砂
掌的功夫，江湖上無人能敵。黑白無常兩兄弟是川江上著名的俠盜，
一向劫富濟貧，不過心狠手辣，因此得了這難聽的外號。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 500000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("strike", 120);
	set_skill("honghua-shengong", 120);
	set_skill("youlong-shenfa", 180);
	set_skill("heisha-zhang", 180);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("parry", "heisha-zhang");
	map_skill("strike", "heisha-zhang");
	prepare_skill("strike", "heisha-zhang");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({				
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("double_attack", 1);
	create_family("紅花會", 2, "弟子");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="chang hezhi")
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

