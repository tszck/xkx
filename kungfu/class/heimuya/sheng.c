// danqing-sheng.c 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("丹青生", ({ "danqing sheng", "sheng" }));
	set("long",
		"他就是梅莊四位莊主排行第四的丹青生。\n"
		"身穿一件乾乾淨淨的青色長袍。\n"
		"他已年愈四旬，身材瘦長，滿臉紅光。恬淡沖和，沉默寡言。\n");
	set("gender", "男性");
	set("age", 41);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("env/wimpy", 40);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("painting", 100);         // 潑墨丹青
	set_skill("literate", 100);         // 讀書識字
	set_skill("force", 80);             // 基本內功
	set_skill("dodge", 80);             // 基本躲閃
	set_skill("parry", 80);             // 基本招架
	set_skill("sword", 80);             // 基本劍法
	set_skill("piaoyibu", 120);          // 飄逸步法
	set_skill("pomopima-jian", 120);    // 潑墨披麻劍
	set_skill("kuihua-xinfa", 80);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "pomopima-jian");
	map_skill("sword", "pomopima-jian");

	set("inquiry", ([
		"令牌"     : (: ask_me :),
		"日月神教" : "你想加入我日月神教，就得找四大堂長老。",
		"入教"     : "你想加入我日月神教，就得找四大堂長老。",
	])); 
	set("item_count", 1);
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIG"梅莊四莊主"NOR);
	create_family("黑木崖", 9, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂長老入教去！\n");
		return;
	}
	if ((int)ob->query("shen") < 0)
	{
		command("say 本教雖不是什麼名門正派，但在梅莊，擇徒也極為嚴格。");
		command("say 在品行方面，" + RANK_D->query_respect(ob) +
			"是否還做得不夠？");
		return;
	}
	command("say 好吧，老夫就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "黑木崖")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (query("item_count") < 1)
		return "你來晚了，梅花令牌不在此處。";
	add("item_count", -1);
	ob = new("/d/meizhuang/npc/obj/lingpai");
	ob->move(this_player());
	return "好吧，這塊梅花令牌就交給你保管了。";
}

