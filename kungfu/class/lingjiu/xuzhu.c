// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("虛竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",
		"這是一個二十五六歲的年輕人，濃眉大眼，大大的鼻子扁平下塌，容貌
頗為醜陋。身穿一件華貴雅緻的長袍，倒使他更顯幾分精神。
他就是天山童姥的救命恩人。\n");
	set("title", "靈鷲宮第二代掌門人");
	set("gender", "男性");
	set("age", 26);
	set("nickname", HIR "夢郎" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 20000);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike", 200);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("tianyu-qijian", 300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 200);
	set_skill("beiming-shengong",200);
	set_skill("hunyuan-yiqi",100);
	set_skill("shaolin-shenfa",100);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("sword", "tianyu-qijian");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.san" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );	
	set("no_teach", ([
		"beiming-shengong" : "唉……這是師尊注如我體內的，教我怎麼教給你？",
                "hunyuan-yiqi"     : "…這…這東西我都沒學好。",
                "shaolin-shenfa"   : "…這個…嗯…我還是教你本門的輕功好了。",
	]));
	create_family("逍遙派",2,"掌門");
	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/food/jiudai");
	add_money("silver",50);
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
	{
		command("say " + RANK_D->query_respect(ob) + "是否還應該多練練八荒六合唯我獨尊功？");
		return;
	}  
	if ((string)ob->query("gender")=="女性")
	{
  	      command("nod");
  	      command("say 今日小僧…在下就收下你，以後你要多做好事。");
  	      command("say 另外，以後若遇到了少林寺的大師，可千萬不能和他們為難。");
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("虛竹瞪着你看了半天,説道：“閣下不會是想來搶我的生意吧?”\n",ob);
		return;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		ob->set("title","靈鷲宮第三代弟子");
	}
}