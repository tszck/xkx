// zi.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黑白子", ({ "heibai zi", "zi" }));
	set("long",
		"他就是梅莊四位莊主排行第二的黑白子。\n"
		"身穿一件乾乾淨淨的黑色長袍。臉色卻極白。\n"
		"他已年愈五旬，身材高大，雙眼神光內斂, 一望便知是一位內家的高手。\n");
	set("gender", "男性");
	set("age", 52);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("env/wimpy", 40);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);
	set("combat_exp", 1000000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("goplaying", 100);        // 紋枰手談
	set_skill("literate", 100);         // 讀書識字
	set_skill("force", 120);            // 基本內功
	set_skill("finger", 120);           // 基本指法
	set_skill("dodge", 120);            // 基本躲閃
	set_skill("parry", 120);            // 基本招架
	set_skill("piaoyibu", 180);         // 飄逸步法
	set_skill("xuantian-zhi", 180);	    // 玄天無情指
	set_skill("kuihua-xinfa", 120);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "xuantian-zhi");
	prepare_skill("finger", "xuantian-zhi");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂長老。",
		"入教"     : "你想加入我日月神教，就得找四大堂長老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIB"梅莊二莊主"NOR);
	create_family("黑木崖", 9, "弟子");

	setup();
	carry_object("/d/meizhuang/npc/obj/heiyi")->wear();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂長老入教去！\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa", 1) < 90)
	{
		command("say 想學我教功夫，在內功上，" + RANK_D->query_respect(ob) + "是否還應該多下點功夫？");
		return;
	}
	command("say 好吧，在下就收下你了。");
	command("recruit " + ob->query("id"));
}

