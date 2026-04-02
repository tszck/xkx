// zhanchun.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("詹春", ({ "zhan chun", "zhan", "chun" }));
	set("long",
		"她是何太沖最喜歡的弟子，長得倒也頗爲俏麗。\n");
	set("gender", "女性");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 600);
	set("max_jing", 400);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 40);
	set_skill("xuantian-wuji", 65);
	set_skill("dodge", 60);
	set_skill("taxue-wuhen", 65);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei-sword", 65);
	set_skill("leg", 50);
	set_skill("chuanyun-leg", 60);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("leg", "chuanyun-leg");
	map_skill("sword", "xunlei-sword");
	prepare_skill("leg", "chuanyun-leg");

	create_family("崑崙派", 5, "弟子");
	set("env/wimpy", 60);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="男性")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"，師母不准我收男弟子，你去找我師兄去吧。");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say 師祖怎敢開如此玩笑，晚輩卻是萬萬不敢的！");
		return;
	}

	command("say 好吧，我就收下你，教你一些皮毛功夫。");
	command("recruit " + ob->query("id"));
}

