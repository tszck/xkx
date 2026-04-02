// gaozecheng.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("高則成", ({ "gao zecheng", "gao" }));
	set("long",
		"他穿青色長袍，背上斜插長劍，二十八九歲年紀。\n"
		"臉罩寒霜，一副要惹事生非的模樣。\n");
	set("gender", "男性");
	set("class", "taoist");
	set("age", 20);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per", 22);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 150000);
	set("score", 10000);

	set_skill("force", 80);
	set_skill("xuantian-wuji", 85);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 90);
	set_skill("parry", 80);
	set_skill("sword", 85);
	set_skill("xunlei-sword", 95);
	set_skill("cuff", 80);
	set_skill("zhentian-cuff", 90);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-sword");
	map_skill("cuff", "zhentian-cuff");
	prepare_skill("cuff", "zhentian-cuff");

	create_family("崑崙派", 5, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender")=="女性")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"，師母不准我收女弟子，你去找我師姊吧。");
		return;
	}
	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say 前輩怎敢開這等玩笑，真是折殺做晚輩的了。");
		return;
	}
	command("say 既然"+RANK_D->query_respect(ob)+
	"慕崑崙派之名，千里而來，我崑崙派自當廣納天下英才，我就收下你吧。");
	command("recruit " + ob->query("id"));
}
