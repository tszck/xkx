// zhaixing.c 摘星子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_book();
string ask_job();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing", "zi" }));
	set("nickname", "星宿派大師兄");
	set("long", 
		"一個二十七八歲的白衣年輕人。他身材高瘦，臉色青
中泛黃，面目卻頗英俊。眼光中透出一絲乖戾之氣。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);
	set("di_count", 10);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("throwing", 70);
	set_skill("feixing-shu", 80);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 80);
	set_skill("chousui-zhang", 80);
	set_skill("claw", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("parry", 70);
	set_skill("poison", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"星宿派"    : "你想加入，就拜我爲師。",
		"星宿海"    : "去星宿海幹什麼？拜我爲師就夠你學的了。",
		"丁春秋"    : "丁春秋是你叫的嗎？沒大沒小的。以後叫老仙！",
		"老仙"      : (: ask_job :),
		"job"       : (: ask_job :),
		"煉心彈"    : (: ask_me :),
		"祕籍"      : (: ask_book :),
		"天山器法"  : (: ask_book :),
	]));
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
	}));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (query("dan_count") < 1)
		return "你來晚了，沒有練心彈了。";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "這些練心彈夠你用的了吧。";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (query("book_count") < 1)
		return "你來晚了，現在沒什麼剩的了。";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "好吧，這本書你拿回去好好看看吧。";
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "星宿派")
	{
		say("摘星子對"+ob->name()+"理都不理。\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1)<90 || ob->query("shen") > -50000)
	{
		command("say 你的條件還不夠，我纔不想收你呢。");
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
 
	if(!fam) return "看得出你對老仙態度恭敬，何不加入我星宿派呢？";
	if(fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
		return "你對老仙的態度看上去不太恭敬啊！";
	if(exp<500000)
		return "哈哈哈，你再加把力練功吧。";
	if(exp>=750000)
		return "老仙最近的情況我不太清楚，你自己去問問他老人家吧。";
	if(me->query_condition("wait_xx_task"))
		return "上次搞砸了，這次你就等等吧。";
	if(interactive(me) && me->query_temp("xx_job"))
		return "你怎麼還在這裏發呆？";
	if(interactive(me) && me->query_condition("wait_xx_task"))
		return "老仙現在心情還好，不用你來爲他分憂。";
	if(query("di_count") < 1)  
		return "老仙現在心情還好，你別再來煩我了。";
	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", MAG "紫玉短笛" NOR);
	ob->set("long", MAG"這玉笛短得出奇，只不來七寸來長、通體紫紅，晶瑩可愛。\n" NOR);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "星宿派")
		me->set_temp("apply/short", ({MAG"星宿派門客 "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N拿出一隻玉製短笛，交給$n。\n", this_object(), me);
	return "老仙最近心情不佳，你可要多多爲他老人家分憂纔是！\n";    
}
