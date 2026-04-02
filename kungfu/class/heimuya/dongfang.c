// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void consider();

void create()
{
	object ob;
	set_name("東方不敗", ({"dongfang bubai", "dongfang", "bubai", "dong"}));
	set("nickname", HIY "武功天下第一" NOR );
	set("gender", "無性");
	set("class", "eunach");
	set("shen_type", -1);
	set("age", 42);
	set("long", "他就是日月神教教主。據傳武功天下第一，因此大號就是「東方不敗」。\n");
	set("attitude", "peaceful");

	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("no_get",1);

	set("chat_chance", 1);
	set("chat_msg", ({
		"東方不敗嘆了口氣道：“唉 …… 我的楊大哥…他怎麼還不回來，我好掛念他 ……東方不敗眼中流露無限迷茫。\n",
	}));
	set("inquiry", ([
		"楊蓮亭"   : "你敢直稱我愛人的名字，想找死呀？ \n",
		"葵花寶典" : "如果你能幫我取得葵花寶典上冊，我一定重重謝你。\n",
		"日月神教" : "你想加入我日月神教，就得找四大堂長老。",
		"入教"     : "你想加入我日月神教，就得找四大堂長老。",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 400);

	set("combat_exp", 3000000);
	set("score", 0);

	set_skill("literate", 100);         // 讀書識字
	set_skill("force", 200);            // 基本內功
	set_skill("finger", 200);           // 基本指法
	set_skill("unarmed", 200);          // 基本拳腳
	set_skill("dodge", 200);            // 基本躲閃
	set_skill("parry", 200);            // 基本招架
	set_skill("dagger", 200);           // 基本刺法
	set_skill("sword", 200);            // 基本劍法
        set_skill("shigu-bifa", 300);       // 石鼓打穴筆法
	set_skill("piaoyibu", 300);         // 飄逸步法
	set_skill("bixie-jian", 250);       // 辟邪劍法
	set_skill("wuyun-jian", 300);       // 五韻七絃劍
	set_skill("xuantian-zhi", 300);	    // 玄天無情指
	set_skill("kuihua-xinfa", 200);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "bixie-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "bixie-jian");
	map_skill("parry", "bixie-jian");

	prepare_skill("finger", "xuantian-zhi");

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIM"第八代教主"NOR);
	create_family("黑木崖", 8, "弟子");

	setup();
	if (clonep())
	 {
	 	ob=new(WEAPON_DIR"treasure/zhen");
	 	if ( ob->violate_unique() )
	 	{
	 		destruct(ob);
	 		ob=new(WEAPON_DIR"changjian");
	 	}
	 	ob->move(this_object());
	 	ob->wield();
	 }
  carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂長老入教去！\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 150)
	{
		command("say 在我教的內功上，" + RANK_D->query_respect(ob) + "是否還應該多下點功夫？");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 我不收資質差的弟子，您請回吧！\n");
		return;
	}
	if (ob->query("gender") != "無性" )
	{
		command("say 要練神功，必須自宮。");
		return;
	}
	if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000)
	{
		command("say 我黑木崖與世隔絕，向來不與您這種成名人物打交道，您請回吧！\n");
		return;
	}
	command("say 很好，很好。\n");
	command("recruit " + ob->query("id"));
}

