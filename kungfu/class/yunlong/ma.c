// ma.c 馬超興

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int do_join(string arg);
int ask_weiwang();
string ask_me();

void create()
{
	set_name("馬超興", ({ "ma chaoxing", "ma"}));
	set("gender", "男性");
	set("long", "他就是天地會家後堂香主，矮矮胖胖的個，善使一柄大刀。\n");
	set("class", "fighter");
	set("age", 45);

	set("int", 30);
	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1200); 
	set("max_neili", 1200);
	set("jiali", 20);
	set("shen_type", 1);

	set("combat_exp", 250000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 70);
	set_skill("blade", 100);
	set_skill("whip", 70);
	set_skill("yunlong-shengong", 70);
	set_skill("yunlong-shenfa", 70);
	set_skill("wuhu-duanmendao", 80);
	set_skill("houquan", 50);
	set_skill("yunlong-jian", 50);
	set_skill("yunlong-bian", 50);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 25);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("blade","wuhu-duanmendao");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
	map_skill("unarmed","houquan");

	set("party/party_name", HIR"天地會"NOR);
	set("party/rank", HIW"家後堂"HIC"香主"NOR);
	create_family("雲龍門", 2, "弟子");
	set("book_count", 1);
	set("inquiry", ([
		"陳近南" : "江湖威望值達到70就可以拜總舵主為師。\n",
		"天地會" : "只要是英雄好漢，都可以入我天地會(join tiandihui)。\n",
		"入會" : "只要入了我天地會，可以向會中各位好手學武功。\n",
		"反清復明" : "去藥鋪和棺材店仔細瞧瞧吧！\n",
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
		"雲龍經" : (: ask_me :),
	]) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 這位" +RANK_D->query_respect(this_player())+"，你我無冤無仇，何必如此?\n") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: perform_action, "sword.xian" :),
		(: perform_action, "whip.chan" :),
		(: perform_action, "whip.chan" :),
		(: perform_action, "blade.duan" :),
		(: perform_action, "blade.duan" :),
		(: perform_action, "blade.duan" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
	}) );
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	carry_object(WEAPON_DIR"changbian")->wield();
	carry_object(WEAPON_DIR"changjian");
	carry_object(__DIR__"obj/dadao");
	add_money("silver",20);
}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
	add_action("do_join","join");
	add_action("do_skills","skill");
	add_action("do_skills","cha");
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n馬超興説道：如果你威望值很高，有些人見了你不但不會殺你，還會教你武功，送你寶貝。\n"
	+"而且你還可以加入幫會，率領會眾去攻打目標，就連去錢莊取錢也會有利息 。。。。。\n");
	say("馬超興又説：殺某些壞人或救某些好人可以提高江湖威望。\n");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "雲龍門")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if (query("book_count") < 1)
		return "你來晚了，本派的雲龍真經不在此處。";
	add("book_count", -1);
	ob = new("clone/book/yljing1");
	ob->move(this_player());
	return "好吧，這本「雲龍經」你拿回去好好鑽研。";
}

void attempt_apprentice(object ob)
{
/*
	if((string)ob->query("gender")=="女性")
	{
		command("say 女人的名字是弱者，我雲龍門頂天立地，怎會收你呢？！");
		return;
	}
*/
	if((string)ob->query("gender")=="無性")
	{
		command("say 雲龍門頂天立地，怎會收你這樣的廢人？！");
		return;
	}
	if (ob->query("party/party_name") != HIR "天地會" NOR )
	{
		command("say 你不是本會弟兄，我不能收你！");
		return;
	}
	if ((int)ob->query_skill("yunlong-shengong",1) < 60 )
	{
		command("say 你的本門內功心法太低了,還是努努力先提高一下吧!");
		command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我輩中人，今天就收下你吧。");
		command("recruit " + ob->query("id"));
		if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
	}
}
void greeting(object ob)
{
	if(random(5)<2) say( "馬超興笑道：這位" + RANK_D->query_respect(ob)
		+ "，可有什麼不平之事麼？\n");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="ma" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != HIR "天地會" NOR )
	{
		message_vision("$N搖了搖頭。\n",this_object());
		command("tell "+ob->query("id")+" 不是天地會弟子不能察看。\n"); 
		return 1;
	}
	command("tell "+ob->query("id")+" 我所有的基本武功如下：\n"+
	"  基本刀法 (blade)                         - 深不可測 100/    \n"+
	"  基本輕功 (dodge)                         - 登峯造極  80/    \n"+
	"  基本內功 (force)                         - 登峯造極  80/    \n"+
	"  基本招架 (parry)                         - 登峯造極  80/    \n"+
	"  基本劍法 (sword)                         - 出神入化  70/    \n"+
	"  基本拳腳 (unarmed)                       - 登峯造極  80/    \n"+
	"  基本鞭法 (whip)                          - 出神入化  70/    \n"+
	"□五虎斷門刀 (wuhu-duanmendao)             - 登峯造極  80/    \n"+
	"□猴拳 (houquan)                           - 出類拔萃  50/    \n"+
	"□雲龍鞭 (yunlong-bian)                    - 出類拔萃  50/    \n"+
	"□雲龍劍法 (yunlong-jian)                  - 出類拔萃  50/    \n"+
	"□雲龍身法 (yunlong-shenfa)                - 出神入化  70/    \n"+
	"□雲龍神功 (yunlong-shengong)              - 出神入化  70/    \n");
	 return 1;
}
#include "tiandihui.h";
