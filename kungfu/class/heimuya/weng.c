// weng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("禿筆翁", ({ "tubi weng", "weng" }));
        set("long",
                "他就是梅莊四位莊主排行第三的禿筆翁。\n"
                "身穿一件乾乾淨淨的白色長袍。\n"
                "他已年愈五旬，身材矮小，頂上光光, 一看就知道是個極易動怒的人。\n");
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
        set("max_jing", 1400);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 80);
        set("combat_exp", 1000000);
        set("shen", 15000);
        set("score", 60000);

	set_skill("literate", 100);         // 讀書識字
	set_skill("force", 100);            // 基本內功
	set_skill("dodge", 100);            // 基本躲閃
	set_skill("parry", 100);            // 基本招架
	set_skill("dagger", 100);           // 基本刺法
  set_skill("shigu-bifa", 150);       // 石鼓打穴筆法
	set_skill("staff",100);             // 基本杖法
  set_skill("jiangjun-zhang",150);    // 裴將軍詩杖法
  set_skill("piaoyibu", 150);         // 飄逸步法
	set_skill("kuihua-xinfa", 100);	    // 葵花心法
  set_skill("xuantian-zhi",100);

	map_skill("force", "kuihua-xinfa");
	map_skill("dagger", "shigu-bifa");
        map_skill("dodge", "piaoyibu");
        map_skill("staff", "jiangjun-zhang");
        map_skill("parry", "shigu-bifa");
	prepare_skill("finger", "xuantian-zhi");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂長老。",
		"入教"     : "你想加入我日月神教，就得找四大堂長老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", WHT"梅莊三莊主"NOR);
        create_family("黑木崖", 9, "弟子");

        setup();
        carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wield();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂長老入教去！\n");
		return;
	}
        if ((int)ob->query_skill("kuihua-xinfa",1) < 60)
	{
                command("say 要百尺竿頭更進一步，" + RANK_D->query_respect(ob) + "是否還在我教的內功上多下點功夫？");
                return;
        }
        command("say 好吧，老夫就收下你了。");
        command("recruit " + ob->query("id"));
}

