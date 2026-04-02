// xu.c 靜虛師太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
int peiyao();
int liandan();
void create()
{
	set_name("靜虛師太", ({ "jingxu shitai","jingxu","shitai"}));
	set("long", "她是峨嵋派二師姐，峨嵋門下多年，一套峨嵋掌法名動江湖。據説
對配藥和煉製霹靂彈頗有造詣。\n");
	set("gender", "女性");
	set("age", 43);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 10000);
	set("class", "bonze");
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"配藥"  : ( : peiyao :),
		"霹靂彈": ( : liandan : ),
		"還俗"  : "峨嵋弟子，不能還俗。你找掌門師太吧。",
	]));

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);

	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("finger", 100);
	set_skill("parry", 90);
	set_skill("strike", 80);
	set_skill("blade", 100);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding-zhang", 120);
	set_skill("tiangang-zhi", 150);
	set_skill("yanxing-dao", 150);
	set_skill("zhutian-bu", 150);
	set_skill("linji-zhuang", 100);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "sword.mie" :),
		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}
void init()
{
	add_action("do_kneel", "kneel");
}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿彌陀佛！貧尼不收弟子。\n");
		command ("say 你若想繼續學峨嵋派的功夫，還是去找我俗家師妹吧。\n");
		return;
	}

	if( (string)ob->query("gender") != "女性" )
	{
		command ("say 阿彌陀佛！貧尼不收男弟子。施主若想學藝可去找我俗家師妹。");
		return;
	}
	if ((int)ob->query("shen") < 100)
	{
		command("say " + RANK_D->query_respect(ob) + "你行俠仗義之事還做的不夠。");
		return;
	}
	if ((int)ob->query_skill("mahayana",1) <50)
	{
		command("say 你大乘佛法的修為還要提高些。");
		return;
	}
	command("say 阿彌陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，濟度眾生。");
	command("recruit " + ob->query("id"));
}

int peiyao()
{
	object me = this_player();
 
	object obj;
	int i;

	if(!objectp(present("caoyao 3",me)))
	{
		command("say 你的身上沒有那麼多草藥。");
		return 1;
	}
	for(i=0;i<3;i++)
	{
		obj=present("caoyao",me);
		destruct(obj);
	}
	command("smile");
	command("say 好吧，我就給你配藥了。");
	obj=new("/d/emei/obj/zhongyao");
	obj->move(me);
	message_vision("靜慈師太給$N一包中藥。\n",me);
	return 1;
}
int liandan()
{
	object me = this_player();
 
	object obj;
 
	if(!objectp(present("liuhuang",me)))
	{
		command("say 你的身上沒有煉製霹靂彈用的硫磺。");
		return 1;
	}
	obj=present("liuhuang",me);
	destruct(obj);
	command("smile");
	command("say 好吧，我就給你煉製一粒霹靂彈。");
	obj=new("/d/emei/obj/pilidan");
	obj->move(me);
	message_vision("靜慈師太給$N一粒霹靂彈。\n",me);
	return 1;
}
#include "emei.h"