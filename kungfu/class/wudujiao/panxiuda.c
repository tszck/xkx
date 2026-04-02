// panxiuda.c
// 潘秀達
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("潘秀達", ({ "pan xiuda", "pan" }));
	set("nickname", HIG "笑面閻羅" NOR);
	set("long",@LONG
他就是五毒教的左護法，人稱笑面閻羅的潘秀達。別看他一臉笑眯眯的
，但是常常殺人於彈指之間，一手五毒鉤法也已達到登峯造極的境界。
LONG
	);
	set("title","五毒教護法");
	set("gender", "男性");
	set("class", "shaman");
	set("age", 38);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", 120);
	set_skill("wudu-shengong", 120);
	set_skill("dodge", 130);
	set_skill("wudu-yanluobu", 170);
	set_skill("hand", 120);
	set_skill("qianzhu-wandushou", 180);
	set_skill("strike", 120);
	set_skill("wudu-zhang", 180);
	set_skill("parry", 120);
	set_skill("hook", 140);
	set_skill("wudu-goufa", 180);
	set_skill("sword", 140);
	set_skill("qingmang-sword", 180);
	set_skill("five-poison", 110);
	set_skill("literate", 80);
	map_skill("force", "wudu-goufa");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "hand.qzwd" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("五毒教", 12, "護法");
	setup();

	carry_object("/d/wudujiao/npc/obj/ganggou")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();

	add_money("silver",10);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "無性")
	{
		command("say 這位公公不要開玩笑了。");
		command("say 這位" + RANK_D->query_respect(ob) + "還是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > -5000)
	{
		command("say 做我五毒教弟子必須心狠手辣。");
		command("say 這位" + RANK_D->query_respect(ob) + "心慈手軟，可惜與我教沒有緣分啊！");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 這位" + RANK_D->query_respect(ob) + "不是本教弟子，還是請回吧！");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 60)
	{
		command("say 我五毒教弟子以毒殺人，修習毒技是首要的。");
		command("say 這位" + RANK_D->query_respect(ob) + "是否還應該多多鑽研本門的絕學？");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 60)
	{
		command("say 你的五毒神功還學的不夠啊。");
		return;
	}

//	command("chat 嘿嘿嘿嘿！！！！！");
//	command("chat 該當我五毒教發揚光大，稱霸武林指日可待了。");
//	command("chat 嘿嘿嘿嘿！！！！！");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"五毒教弟子"NOR);
	return;
}

