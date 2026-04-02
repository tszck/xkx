// Npc: /d/lingxiao/npc/hua.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("花萬紫",({"hua wanzi","hua","wanzi"}));
	set("nickname", HIW"寒梅女俠"NOR);
	set("gender", "女性");
	set("age", 20);
	set("long", "她是凌霄城第六代弟子花萬紫。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("max_qi", 1200);
	set("qi", 1200);

	set("combat_exp", 200000);
	set("shen_type", 1);
	set("score", 20000);

	set("env/wimpy", 60);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.xuehua" :),
		(: perform_action, "sword.wanmei" :),
		(: perform_action, "sword.fengxue" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 100);
	set_skill("snow-strike", 150);
	set_skill("snowstep", 150);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 20)
	{
		command("say 你這種資質,不宜學劍！");
		return;
	}
	if( (string)ob->query("gender") != "女性" )
	{
		command("say 這位"+RANK_D->query_respect(ob)+"我不收男徒的，你還是去找我師兄們吧。");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
} 

