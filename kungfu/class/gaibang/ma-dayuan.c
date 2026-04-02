// ma-dayuan.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("馬大元", ({"ma dayuan", "ma", "dayuan"}));
	set("gender", "男性");
	set("age", 29);
	set("long", 
"他就是丐幫第十任副幫主，辦事謹慎仔細，是幫中一把好手。
一手鎖喉擒拿手威震武林。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

        set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 180);             // 基本內功
	set_skill("huntian-qigong", 180);    // 混天氣功
	set_skill("dodge", 150);      	     // 基本躲閃
	set_skill("xiaoyaoyou", 150);        // 逍遙遊
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法
	set_skill("suohou-hand", 300);       // 鎖喉擒拿手
	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-blade", 180);       // 四象六合刀
	set_skill("begging", 100);           // 叫化絕活
	set_skill("checking", 100);          // 道聽途説
	set_skill("training", 100);          // 馭獸術
	set_skill("strike",85);  // 基本掌法
	set_skill("lianhua-zhang",85); // 蓮花掌
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	prepare_skill("hand",  "suohou-hand");

	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", RED"副幫主"NOR);
	set("party/level", 10);
	create_family("丐幫", 10, "弟子");

	setup();
	
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20)
	{
		command("say 當叫化子需要能喫苦耐勞，依我看" + RANK_D->query_respect(ob) + "的資質似乎不適合當叫化子？");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐幫")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名師指點，何必又來拜老叫化呢？");
		return;
	}
	if ((string)ob->query("party/party_name") != HIC"丐幫"NOR)
	{
		command("say 我只收本幫弟子為徒。\n");
		return;
	}
	command("recruit "+ob->query("id"));
}

