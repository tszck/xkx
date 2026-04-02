// mo.c 莫聲谷

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init();
int accept_object(object who, object ob);

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
	set_name("莫聲谷", ({ "mo shenggu", "mo" }));
	set("nickname", "武當七俠");
	set("long","他就是張三豐的最小弟子、武當七俠之末的莫聲谷。\n身穿一件乾乾淨淨的灰色道袍。\n他自幼便少年老成，脾氣粗豪直爽，長得魁梧奇偉，滿臉的濃髯。\n武功內外兼修、剛柔合一。\n");
	set("gender", "男性");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 26);

	set("max_qi", 1800);
	set("max_jing", 800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jingli", 1800);
	set("max_jingli", 1800);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 60000);
	set("wudang/raozhi", 1);
	set("first_ask", 1);
	set("set_gocatch", 1);

	set_skill("force", 80);
	set_skill("taiji-shengong", 90);
	set_skill("dodge", 90);
	set_skill("tiyunzong", 120);
	set_skill("unarmed", 80);
	set_skill("taiji-quan", 120);
	set_skill("parry", 90);
	set_skill("sword", 90);
	set_skill("taiji-jian", 120);
	set_skill("liangyi-jian", 120);
	set_skill("wudang-quan", 120);
	set_skill("wudang-jian", 120);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("chat_chance", 20);
	set("chat_msg", ({
	"莫聲谷輕聲說道：在石柱面壁可以大有收穫的。\n",
	"莫聲谷斜了你一眼：不過邪魔外道就不能面壁的了。\n",
	"莫聲谷自豪地說道：只有我武當纔是天下的正宗。\n",
	"莫聲谷對張三豐的欽仰溢於言表：如果想成爲絕頂高手，一定要學道德經。\n"
	"莫聲谷說道: 你知道江湖上的朋友爲什麼都尊稱我們一聲武當七俠嗎？\n",
	"莫聲谷說道: 身爲武當弟子應時時以俠義爲先，你要切記啊！\n",
	"莫聲谷說道: 何爲俠義之道？你自己好好想清楚吧。 \n",
	"莫聲谷說道: 青書那個畜生不知道躲哪去了，上次在峨嵋真不應該讓他逃掉。\n"
	"莫聲谷說道: 下次再見到青書一定不能讓他再跑了。 \n",
	}));
	set("inquiry", ([
		"繞指柔劍" : (: ask_me :),
		"raozhi"   : (: ask_me :),
		"宋青書"   : (: ask_me1 :),
		"qingshu"  : (: ask_me1 :),
		"teach"    : (: ask_me2 :),
		"指教"     : (: ask_me2 :),
		"石柱"     : "在石柱面壁可以大有收穫的。",
		"面壁"     : "面壁是一定要註明技能的。",
		"張三豐"   : "我恩師學究天人，尤其是他的道學心法。"
	]));

	create_family("武當派", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
void init()
{
	object ob, me = this_player();
	
	::init();
	
	if(present("song qingshu", environment(me)))
	{
		command("sigh qingshu");
		call_out("qingshustory", 1, ob);
	}
	if( interactive(ob = this_player()) &&
		ob->query("family/family_name") == "武當派" )
		call_out("greeting", 1, ob);
}

void greeting(object me)
{
	command("nod " + me->query("id"));
}

string ask_me()
{
        mapping fam; 
        object ob, *obs, me = this_player();
       		                
        if (me->query("can_fight") ) 
   	{
		add_action("do_fight", "fight");
		command ("ok");
		me->delete("can_fight");
		me->set("can_teach", 1);   
		me->set("fight_mo", 1);
		command("fight " + me->query("id"));
		return "既然你幫我抓到了本派叛徒，你我可算有緣，就讓我先試試你的身手吧。";
	}
        if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武當派")
	{ 
		return RANK_D->query_respect(this_player()) +"有意要加入我武當派？";
	}
        if (query("first_ask") < 1)
	{
		command ("smile");	
		return "「繞指柔劍」正是武當派的絕技。";
	}
  	add("first_ask", -1);
        me->set("know_raozhi", 1);
        command ("hehe");
	return "這路「繞指柔劍」全仗以渾厚內力逼彎劍刃，使劍招閃爍無常，敵人難以擋架。";
}

string ask_me1()
{
	mapping fam; 
	object ob, qingshu, *obs, me = this_player();
        
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武當派")
	{ 
		command ("hmm");               	
		return RANK_D->query_respect(this_player())+"， 青書和你是什麼關係？";
	}	
        if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武當派")
	{ 
		command ("hmm");               	
               	return RANK_D->query_respect(this_player())+"， 請不要再提那個畜生！";
	}
	if (query("set_gocatch") < 1)
	{
		command ("hmm");	
		return "我不想再提起那個畜生！";
	}
  	add("set_gocatch", -1);
        me->set("set_gocatch", 1);
        command ("sigh ");
        return "上次不小心被那個畜生逃走了，真是師門不幸。只可惜自從上次在峨嵋被他逃走後一直找不到他。";
}

int do_fight(string arg)
{
	int i;
	object ob, *inv, me = this_player();

	if ( !arg ) return 0;
	ob = present(arg, environment());
	if (!objectp(ob)) return 0;
	if (me->query("fight_mo", 1)) 
	{       
		tell_object(me,HIR "如果你要和莫聲谷性命相搏，請你也對這個人下一次 kill 指令。\n" NOR);
		message("vision", HIR"如果你要和莫聲谷性命相搏，請你也對這個人下一次 kill 指令。\n看起來莫聲谷想殺死" + me->name() +"\n"NOR, environment(), this_object() );
		fight_ob(this_player());
		add_action("do_halt", "halt");	
		add_action("do_kill", "kill");
		me->delete("fight_mo");
		me->set("halt_mo", 1);
		return 1;
	}
}

int do_halt()
{
	object obj=this_object(), ob = this_player();

	if ( ob->query("halt_mo", 1) )
	{
		ob->delete("halt_mo");
		command("sigh"); 
		command("halt");
		command("say 既然如此，你走吧。我沒有什麼好教你的。");
		return 1;
	}
}

int do_kill(string arg)
{
	int i;
	object ob, *inv, me = this_player();

	if ( !arg ) return 0;
	ob = present(arg, environment());
	if (!objectp(ob)) return 0;
	if ((string)(me->query("family/family_name")) == "武當派" &&
		ob->query("id") == "mo shenggu" )
	{
		message_vision("$N想殺掉$n。\n$n厲聲對$N道：你我本同門，卻爲何想相害於我！\n$n厲聲對$N道：你別妄想學到「繞指柔劍」！\n$n對$N很不滿意！\n" , me, ob);
		command ("sigh");
		command ("disapp");
		ob->delete("halt_mo");
		me->delete("can_fight");       
		me->add("wudang/offerring", -20);
		return 0;    
	}
}

int accept_object(object who, object ob)
{
	object obn;

	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, who) ) return notify_fail("你沒有這件東西。");
	if (who->query("know_raozhi") < 1) 
		return notify_fail("你這麼把青書弄成這樣了！");
	if (who->query("set_gocatch") < 1) 
		return notify_fail("你想幹什麼？");
	if (  (string)ob->query("id") == "song qingshu" )
	{		
		who->delete("set_gocatch");
		who->add("can_fight", 1);
		who->add("wudang/offerring", 10);
		command	("thumb");
		command("touch " + (string)who->query("id")); 
		command("say" + RANK_D->query_respect(who) + "謝謝你幫我抓到了這個叛徒。 \n");
		return 1;
	}
        command("? " + who->query("id"));
        return 0;
}

string ask_me2()
{
	mapping fam; 
	object ob, qingshu, *obs, me = this_player();
 
	if ((int)me->query("can_teach", 1) < 1)
	{
		command ("hmm");
		return "你想請教什麼？";
	}
	if ((int)me->query_skill("sword", 1) < 180)	
	{
		me->delete("can_teach");
		command ("hmm");	
		return "你的劍法功力太淺，不適宜學「繞指柔劍」";
	}
	if ((int)me->query_skill("force", 1) < 180)	
	{
		me->delete("can_teach");
		command ("hmm");	
		return "你的內功火候太淺，不適宜學「繞指柔劍」";
	}
	me->set("wudang/raozhi", 1); 
	me->add("wudang/offerring", 10);        
	me->delete("can_teach");
	command ("ok");
	command ("say" + "你的知質品性深的我心，若你要學我就把「繞指柔劍」傳授於你吧！\n");
	if (!me->query("perform/raozhi"))
	{
		me->set("perform/raozhi",1);
		me->add("perform/number",1);
	}
	return HIW"恭喜你學會了「繞指柔劍」！\n"NOR;
}

