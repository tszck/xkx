// Last Modified by winder on Jul. 15 2001
// bai-wanjian.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("白萬劍",({"bai wanjian","bai"}));
	set("nickname", HIC"氣寒西北"NOR);
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"白萬劍是雪山派掌門人威德先生白自在的長子，他\n"
		"們師兄弟均以“萬”字排行，他名字居然叫到白萬劍，\n"
		"足見劍法之高。他外號氣寒西北，與‘風火神龍’封萬\n"
		"裏合稱‘雪山雙傑’。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("per", 30);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 80);

	set("combat_exp", 1500000);
	set("score", 50000);
	set("inquiry", ([
		"白自在" : "老爺子的臺諱是你叫的嗎！",
		"老爺子" : "你想拜見老爺子嗎？但他閉關面壁，你得找成師叔要到玉牌，才能見到他。",
		"掌門"   : "你想拜見老爺子嗎？但他閉關面壁，你得找成師叔要到玉牌，才能見到他。",
		"玉牌"   : "寒玉牌乃我門中重寶，只有憑它，才能進入監獄。",
	]));
	set("shen_type", 1);

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
	set_skill("force", 120);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 120);
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
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/baihong-jian");
		if ( ob->violate_unique())
		 {
		 	destruct(ob);
		 	ob=new(WEAPON_DIR"changjian");
	 	}
	 	ob->move(this_object());
	 	ob->wield();
	}
	carry_object("/clone/money/gold");
	carry_object(CLOTH_DIR+"bai")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 28)
	{
		command("say 你這種資質，怎能跟我學劍！");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 60 )
	{
		command("say 你的本門內功心法太低了，還是努努力先提高一下吧！");
		return;
	} 
	if ((int)ob->query_skill("xueshan-sword",1) < 80 )
	{
		command("say 你的本門劍法太低了，還是先找你師父提高吧！");
		return;
	}
	if ((int)ob->query_skill("sword",1) < 80 )
	{
		command("say 你的基本劍法太低了，還是先提高基本功吧！");
		return; 
	}
	if ((int)ob->query("shen") < 20000 )
	{
		command("say 學劍須先正身，你做到了嗎?"); 
		return;
	} 
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
} 

