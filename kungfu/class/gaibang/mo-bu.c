// mo-bu.c
// Modified By Venus. Nov.1997

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
	set("gender", "男性");
	set("age", 17);
	set("long",
		"這是位丐幫三袋弟子，看來是個很喫得開的一方霸主。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 3);
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 140);
	set("max_jing", 140);
	set("neili", 180);
	set("max_neili", 180);
	set("jiali", 15);
	set("combat_exp", 18000);
	set_skill("force", 40);
	set_skill("huntian-qigong", 40);
	set_skill("hand", 40);
	set_skill("suohou-hand", 40);
	set_skill("dodge", 40);
	set_skill("xiaoyaoyou", 40);
	set_skill("parry", 40);
	set_skill("begging", 40);
	set_skill("checking", 40);
	set_skill("lianhua-zhang",40);
	set_skill("jianlong-zaitian",40);
	set_skill("strike",40);
	map_skill("strike","jianlong-zaitian");
	prepare_skill("strike", "jianlong-zaitian");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", MAG"三袋弟子"NOR);
	set("party/level", 3);
	create_family("丐幫", 20, "弟子");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "男性") return;
	command("say 好吧，希望你能好好學習本門武功，將來爲丐幫爭一口氣！。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
