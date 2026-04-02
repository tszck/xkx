// tianlang.c 天狼子
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job();

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang", "zi" }));
	set("nickname", "星宿派三弟子");
	set("long", "一個貌似忠厚，其實十分狡獪的胖子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);
	set("di_count", 10);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 30);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 30);
	set_skill("parry", 40);
	set_skill("poison", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("env/wimpy", 60);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "strike.biyan" :),
	}));
	create_family("星宿派", 2, "弟子");
	set("inquiry", ([
		"星宿派" : "你想加入，就拜我為師。",
		"星宿海" : "去星宿海幹什麼？拜我為師就夠你學的了。",
		"丁春秋" : "丁春秋是你叫的嗎？沒大沒小的。以後叫老仙！",
		"老仙"   : (: ask_job :),
		"job"    : (: ask_job :),
	]));
	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "星宿派")
	{
		say("天狼子對"+ob->name()+"理都不理。\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1) < 70 || ob->query("shen") > -5000)
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
 
	if(!fam) return "看得出你對老仙態度恭敬，何不先加入我星宿派呢？";
	if (fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
		return "你對老仙的態度看上去不太恭敬啊！";
	if(exp<100000) return "哈哈哈，你再加把力練功吧。";
	if(exp>=250000)
		return "老仙最近的情況我不太清楚，你去問問我師兄獅吼子吧。";
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
	ob->set("name", YEL "黃玉短笛" NOR);
	ob->set("long", YEL"這玉笛短得出奇，只不來七寸來長、通體金黃，晶瑩可愛。\n" NOR);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "星宿派")
	me->set_temp("apply/short", ({YEL"星宿派隨從 "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N拿出一隻玉製短笛，交給$n。\n", this_object(), me);
	return "老仙最近心情不佳，你可要多多為他老人家分憂才是！\n";    
}

