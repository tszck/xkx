// qqzhang.c 裘千丈
// Last Modified by winder on Nov. 17 2001

#include <ansi.h>

inherit NPC;
int ask_qiubai();
int ask_naogui();
void create()
{
	set_name("裘千丈", ({ "qiu qianzhang", "qiu", "qianzhang", "zhang" }));
	set("long", 
		"他是一個白鬚老頭，身穿黃葛短衫，足穿麻鞋，右手揮着一把大蒲扇。\n"
	"他滿臉的油滑無賴的表情。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 30);
	set("con", 26);
	set("dex", 25);
	set("env/wimpy", 70);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 80);
	set("combat_exp", 100000);
	set("score", 40000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("strike", 60);
	set_skill("spear", 60);
	set_skill("parry", 60);
	set_skill("literate", 60);
	set_skill("zhusha-zhang", 90);
	set_skill("tiexue-qiang", 90);
	set_skill("guiyuan-tunafa", 60);
	set_skill("shuishangpiao", 90);

	map_skill("force", "guiyuan-tunafa");
	map_skill("spear", "tiexue-qiang");
	map_skill("strike", "zhusha-zhang");
	map_skill("parry", "zhusha-zhang");
	map_skill("dodge", "shuishangpiao");
	prepare_skill("strike", "zhusha-zhang");

	set("env/wimpy", 60);
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		YEL"裘千丈正色道：你身上已受內傷，快回去密室中休養七七四十九日，不可見風，否則小命不保！\n\n"NOR,
		YEL"裘千丈急道：你再不住手，爺爺可就要不客氣了！！！\n\n"NOR,
		(: random_move :)
	}) );
	
	set("inquiry", ([
		"name" : "記得先父曾給我起過一個名，叫甚麼‘千丈’。我念着不好聽，也就難得用它。\n",
		"here" : "這裏就是鐵掌幫的總壇所在，你如沒事，不要四處亂走，免招殺身之禍！！！\n",
		"上官劍南" : (: ask_qiubai :),
		"鬧鬼" : (: ask_naogui :),
	]));

	set("chat_chance", 10);
	set("chat_msg", ({
		"裘千丈大大咧咧的説道：“鐵掌幫上上下下的事情，沒有爺爺不知道的！”\n",
		"裘千丈神祕的説道：“無名峯上有一座墳墓，聽説那裏經常鬧鬼！”\n",
		"裘千丈神祕的説道：“一旦內功基礎有成，就可以從花草樹木中採氣來提高了！”\n",
		"裘千丈説道：“中指峯第二指節處，有一個神祕的所在，聽説是已故幫主的埋骨之處！”\n",
		(: random_move :)
	}) );
	create_family("鐵掌幫", 14, "弟子");
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
	carry_object(WEAPON_DIR+"spear/tieqiang")->wield();
}

void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > 0)
	{
		command("hehe");
		command("say 他媽的！爺爺我最恨你這樣心慈手軟的小王八蛋！。");
		return;
	}
	command("haha");
	command("say 爺爺我武功蓋世，你這娃娃好好跟着我學，準沒錯！");
	command("recruit " + me->query("id"));
}
int ask_qiubai()
{
	say( "他是鐵掌幫的第十三代幫主。聽説十年前遭了暗算，死在湖北，不知是真是假！\n");
	return 1;
}
int ask_naogui()
{
	say( "聽一些幫眾説，經常聽見無名峯上的墳墓中，傳出響聲！嘿嘿！一定有什麼蹊蹺在裏面！\n");
	this_player()->set_temp("marks/鬧1", 1);
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "怕是活膩了，來來來，讓爺爺教訓教訓你！！\n");
	command( "say 啊喲，糟糕，糟糕，這會兒當真不湊巧！你等一會，我肚子痛，要出恭！\n");
	return 0;
}
