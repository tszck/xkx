// li-futou.c
// Modified by Venus. Nov.1997

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("李斧頭", ({"li futou", "li", "futou"}));
	set("gender", "男性");
	set("class", "beggar");
 	set("beggarlvl", 6);
	set("age", 20);
	set("long",
		"這是位丐幫六袋弟子，看來是個深藏不露的高手。\n");
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 27);
	set("max_qi", 250);
	set("max_jing", 220);
	set("neili",300);
	set("max_neili", 300);
	set("jiali",30);
	set("combat_exp", 60000);

	set_skill("force", 60);
	set_skill("huntian-qigong", 60);
	set_skill("blade", 60);
	set_skill("liuhe-blade", 60);
	set_skill("hand", 60);
	set_skill("suohou-hand", 60);
	set_skill("dodge", 60);
	set_skill("xiaoyaoyou", 60);
	set_skill("parry", 60);
	set_skill("begging", 60);
	set_skill("checking", 60);
	set_skill("lianhua-zhang",60);
	set_skill("zhenjing-baili",60);
	set_skill("strike",60);
	map_skill("strike","zhenjing-baili");
	prepare_skill("strike", "zhenjing-baili");
	map_skill("force", "huntian-qigong");
	map_skill("blade", "liuhe-blade");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", HIY"六袋弟子"NOR);
	set("party/level", 6);
	create_family("丐幫", 19, "弟子");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

void attempt_apprentice(object ob)					      
{
	if( ob->query("gender") != "男性") return;
	command("say 好吧，希望你能好好學習本門武功，將來為丐幫爭一口氣！。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
