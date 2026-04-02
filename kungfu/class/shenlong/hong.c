// hong.c 洪安通

#include <ansi.h>
#include <localtime.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
inherit F_MANAGER;
string ask_tool();

void create()
{
	set_name("洪安通", ({ "hong antong", "hong", "antong" }));
	set("nickname", HIR "永享仙福" NOR);
	set("long","他年紀甚老，白鬢垂胸，臉上都是傷疤皺紋，醜陋之極。可他就是武功蓋世、令江湖人等談之色變的神龍教教主洪安通。\n");
	set("gender", "男性");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 400000);

	set_skill("force", 200);
 	set_skill("dulong-dafa", 200);
	set_skill("dodge", 200);
	set_skill("yixingbu", 300);
	set_skill("hand", 200);
	set_skill("shenlong-bashi", 300);
	set_skill("strike", 200);
	set_skill("huagu-mianzhang", 300);
	set_skill("finger", 200);
	set_skill("yingxiong-sanzhao", 300);
	set_skill("meiren-sanzhao", 300);
	set_skill("hook", 200);
	set_skill("ruyi-hook", 300);
	set_skill("staff", 200);
	set_skill("shenlong-staff", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("literate", 90);
	set_skill("digging", 200);
	set_skill("leg", 200);
	set_skill("jueming-leg", 300);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("leg", "jueming-leg");
	map_skill("finger", "yingxiong-sanzhao");
	map_skill("hand", "shenlong-bashi");
	map_skill("hook", "ruyi-hook");
	map_skill("staff", "shenlong-staff");
	map_skill("parry", "yingxiong-sanzhao");
	prepare_skill("finger", "yingxiong-sanzhao");
	prepare_skill("hand", "shenlong-bashi");
	set("party/party_name", HIY"神龍教"NOR);
	set("party/rank", HIM"教主"NOR);
	set("party/level", 3);
	create_family("神龍教",1,"弟子");
	set("count", 1);

	set("inquiry", ([
		"神龍教" : "\n一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"入教"   : "\n一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"洪安通" : "\n你不想活了是不是？\n",
		"教主"   : "\n我就是神龍教教主。\n",
		"口號"   : "\n萬年不老！永享仙福！壽與天齊！文武仁聖！\n",
		"掘地"   : "\n你想掘地啊，那得要工具。\n",
		"陷阱"   : "\n你想掘地啊，那得要工具。\n",
		"工具"   : (: ask_tool :),
		"tool"   : (: ask_tool :),
		"鐵鍬"   : (: ask_tool :),
		"神龍鍬" : (: ask_tool :),
		"qiao"   : (: ask_tool :),
	]) );
	set("no_get",1);
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("say 憑你這點膿水，也敢在太歲爺頭上動土？\n") :),
		(: command("say 你活得不耐煩了找死啊？\n") :),
		(: perform_action, "finger.yingxiong" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang3" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 50);
}

int recognize_apprentice(object me)
{
	if( me->query("learnhong")) return 1;
	if ((int)me->query("shen") > -1000)
	{
		command("say 我越看你越象白道派來臥底的。");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
		return 0;
	}
	if( me->query_temp("pending/flatter") )
	{
		command("say 你如此不把我放在眼裏，我又怎能容你？!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
		return 0;
	}
	else
	{
		command("say 我洪安通比起古往今來的聖人怎麼樣啊？");
		message_vision("洪安通微閉雙眼，手捻長鬚，一副等人拍馬(flatter)的樣子。\n",
		this_player());
		me->set_temp("pending/flatter", 1);
	return 0;
	}
}

int do_flatter(string arg)
{
	if( !this_player()->query_temp("pending/flatter") )
		return 0;
	if( !arg ) return notify_fail("你說我什麼？\n");
	this_player()->set_temp("pending/flatter", 0);
	message_vision("$N大聲說道：" + arg + "\n", this_player());
	if( strsrch(arg, "萬年不老") >=0 && (strsrch(arg, "永享仙福") >=0 ||
		strsrch(arg, "壽與天齊") >=0 || strsrch(arg, "文武仁聖") >=0 ))
	{
		command("smile");
		command("say 這還差不多。\n");
		this_player()->set("learnhong", 1);
		command("recruit " + this_player()->query("id"));
	}
	else
	{
		command("say 你如此不把我放在眼裏，我又怎能容你？!");
		this_object()->set_leader(this_player());
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, this_player()); 
	}
	return 1;
}

// 萬年不老,永享仙福,壽與天齊,文武仁聖

void die()
{
	message_vision("\n$N奇道：“咦，居然有人能殺了我，....”說完睜着兩眼倒地死了。\n", this_object());
	::die();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_flatter", "flatter");
	add_action("do_qiecuo","qiecuo");
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))
		{
			set("combat_exp",500000);
			set("qi",10);
			set("jing",10);
		}
	}
	return;
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "神龍教" NOR )
	{
		command("say 你不是本教教衆，想來找死啊！");
		return;
	}
	if ((int)ob->query_skill("dulong-dafa",1) < 60 )
	{
		command("say 你的本門內功心法太低了，還是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > -10000 )
	{
		command( "say 我神龍教與世隔絕，向來不與您這種白道人物打交道，您請回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}

string ask_tool()
{
	mapping fam; 
	object ob, me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "神龍教")
		return "這位"+RANK_D->query_respect(me)+ "與本教素無來往，不知此話從何談起？";
	if( present("shenlong qiao", me) )
		return "你現在身上不是有鍬了嘛，怎麼又來要了？真是貪得無饜！";
	if( me->query_skill("digging", 1) <= 30)
		return "你拿着東西也沒什麼用，還是留給別人吧！";
	if( query("count") < 1)
		return "來晚啦，你要的東西給別人先拿走了！";
	ob = new(__DIR__"obj/shenlongqiao");
	ob->move(me);
	add("count", -1);
	return "好吧，這有一把神龍鍬，你就拿去吧。";
}
#include "/kungfu/class/shenlong/shenlong.h"; 

