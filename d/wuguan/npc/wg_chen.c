// wg_chen.c

inherit NPC;
string do_getling();
void create()
{
	set_name("陳有德", ({ "chen youde", "chen" }));
	set("title", "揚州武館館主");
	set("gender", "男性");
	set("nickname", "鐵掌龍威");	
	set("age", 50);
	set("str", 30);
	set("dex", 26);
	set("long", "這人紫金臉龐，面帶威嚴，威武有力，站在那裏就象是一座鐵塔。\n他好像最近在爲各個門派新人分發推薦令。\n");
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("qi", 2500);
	set("max_qi", 2500);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
	set("inquiry",  ([
	    "工作" : "呵呵，你去找張總管吧，他會安排你的。",
	    "練功" : "東西練武場都可以練的，你去那練吧。",
	    "推薦令" 	:(:do_getling:),
//	    		"job" : (: ask_job :),
	    "ling" :	(:do_getling:),
	]));
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("axe", 80);
	set_skill("blade", 80);
	set_skill("claw", 80);
	set_skill("club", 80);
	set_skill("cuff", 80);
	set_skill("dagger", 80);
	set_skill("finger", 80);
	set_skill("hammer", 80);
	set_skill("hand", 80);
	set_skill("hook", 80);
	set_skill("leg", 80);
	set_skill("spear", 80);
	set_skill("staff", 80);
	set_skill("stick", 80);
	set_skill("strike", 80);
	set_skill("sword", 80);
	set_skill("throwing", 80);
	set_skill("unarmed", 80);
	set_skill("whip", 80);
	set_skill("changquan", 40);
	set_skill("sanshou", 40);
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	setup();
	carry_object("clone/cloth/cloth")->wear();
}



int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 100000)
    {
        message_vision("陳有德望着$N說：你的武功應該歷練江湖才能再長進，不能埋沒
在這裏了。\n", who);
        return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500)
    {
        who->set_temp("marks/yangzhou_paied",1);
        message_vision("陳有德對$N說：好！這位" + RANK_D->query_respect(who) 
+ "想學什麼呢？\n" , who);
        return 1;
    }
    else
        message_vision("陳有德皺眉對$N說：錢我不在乎。可你也給的也太少了點兒吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}
string do_getling()
{
	object ob=this_player();
	object me=this_object();
	object obj;
	if (!ob->query("family"))
		return "這位"+RANK_D->query_respect(ob)+"還沒選好去哪裏學藝吧，留在武館學一些基本功也好。";
	if (ob->query("combat_exp")<20000)
		return "這位"+RANK_D->query_respect(ob)+"似乎太柔弱了些，還是多修煉一段時日再說。";
	if (ob->query("combat_exp")>800000)
		return "大俠您到我們這裏寫回憶錄來了？";
	if (present("ling", ob))
		return "你身上不是有個令了嗎。";
	if (ob->query_temp("getling"))
		return "我剛剛不是纔給過你推薦令了。";
	if (ob->query("teachwg/force")>=100 && ob->query("teachwg/dodge")>=100 && ob->query("teachwg/parry")>=100)
		return "我看這推薦令給你也沒用，還是算了吧。";
	command("smile");
	command("say 這位"+RANK_D->query_respect(ob)+"來得正好，有很多門派派人在我這裏教導新的入門弟子。");
	obj=new(__DIR__"obj/ling");
	obj->move(me);
	ob->set_temp("getling",1);
	command("give ling to "+ob->query("id"));
	return "我這裏有塊推薦令，你先拿去，一定用得上的。";
}


