// shihou.c 獅吼子
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job();
void create()
{
	set_name("獅吼子", ({ "shihou zi", "shihou", "zi" }));
	set("nickname", "星宿派二弟子");
	set("long","他三十多歲，雙耳上各垂着一隻亮晃晃的黃大環，獅鼻闊口，形貌頗
為兇狠詭異。一望而知不是中土人士。\n");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 22);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 30000);
	set("di_count", 10);

	set_skill("force", 60);
	set_skill("huagong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("zhaixinggong", 60);
	set_skill("strike", 70);
	set_skill("chousui-zhang", 40);
	set_skill("claw", 70);
	set_skill("sanyin-wugongzhao", 40);
	set_skill("parry", 60);
	set_skill("poison", 60);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 50);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
	}));
	create_family("星宿派", 2, "弟子");
	set("inquiry", ([
		"星宿派" : "你想加入，就拜我為師。",
		"星宿海" : "去星宿海幹什麼？拜我為師就夠你學的了。",
		"丁春秋" : "丁春秋是你叫的嗎？沒大沒小的。以後叫老仙！", 
		"老仙"   : (: ask_job :), 
		"job"    : (: ask_job :), 
	]));

	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
	carry_object("/d/xingxiu/obj/fire");
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "星宿派")
	{
		say("獅吼子對"+ob->name()+"理都不理。\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1) < 45 || ob->query("shen") > -500)
	{
		command("say 你的條件還不夠，我才不想收你呢。");
		return;
	}
	command("say 好吧，看來你的化功大法有點基礎了，我就收下你吧。");
	command("recruit " + ob->query("id"));
}
string ask_job()
{
	object me, ob;
	mapping fam;
	int shen, exp;
	me = this_player();
	fam = (mapping)me->query("family");
	shen = me->query("shen");
	exp=me->query("combat_exp",1); 

	if(!fam)
		return "看得出你對老仙態度恭敬，何不先加入我星宿派呢？";
	if(fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
		return "你對老仙的態度看上去不太恭敬啊！";
	if(exp<250000)
		return "哈哈哈，你再加把力練功吧。";
	if(exp>=500000)
		return "老仙最近的情況我不太清楚，你去問問我師兄摘星子吧。";
	if(me->query_condition("wait_xx_task"))
		return "上次搞砸了，這次你就等等吧。"; 
	if(interactive(me) && me->query_temp("xx_job"))
		return "你怎麼還在這裏發呆？";
	if(interactive(me) && me->query_condition("wait_xx_task"))  
		return "老仙現在心情還好，不用你來為他分憂。";
	if(query("di_count") < 1)  
		return "老仙現在心情還好，你別再來煩我了。";

	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "星宿派")
		me->set_temp("apply/short", ({WHT"星宿派跟班 "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N拿出一隻玉製短笛，交給$n。\n", this_object(), me);
	return "老仙最近心情不佳，你可要多多為他老人家分憂才是！\n";    
}
