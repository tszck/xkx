// zhixiang.c 制香道長

#include "daozhang.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();
void greeting(object);
int do_say(string);
int do_kill(string);

void create()
{
	set_name("凌虛道長", ({ "lingxu daozhang", "lingxu", "daozhang" }));
	set("long","他就是武當的制香道長，殷梨亭的弟子。每天來武當燒香的人太多了，他和\n他手下的幾個伐木道士都忙不過來了。\n");
	set("gender", "男性");
	set("nickname", "制香道長");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 800);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 70);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 70);
	set_skill("unarmed", 70);
	set_skill("taiji-quan", 70);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("wudang-jian", 60);
	set_skill("wudang-quan", 60);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	set("inquiry", 
	([
		"香火" : "香火練制不易，不能隨便於人，虔誠奉獻者方能得之。\n",
		"進香" : "進香？童言無忌！童言無忌！要説敬香才是！\n",
		"敬香" : "殿堂的香火能綿延不斷，都因為我武當弟子和山外香客及時敬奉。\n",
		"虔誠奉獻" : "虔誠奉獻就是主動多捐獻香火錢，多作義工。\n",
		"敬奉" : "敬奉就是主動多捐獻香火錢，多作義工。\n",
		"松林" : "武當松林在山門附近。\n",
		"柏林" : "武當柏林就在遇真宮後。\n",
		"材料" : "材料就是紅松和青柏，我每天都要派人去砍伐。\n",
		"砍樹" : (: ask_job :),
		"伐木" : (: ask_job :),
		"job"  : (: ask_job :),
		"wook" : (: ask_job :),
		"工作" : "我這裏每天都需要人去砍樹，如果你能主動送些過來，那更好。\n",
		"幹活" : "我這裏每天都需要人去砍樹，如果你能主動送些過來，那更好。\n",
	]));
	set("chat_chance", 5);
	set("chat_msg", ({
		"凌虛道長説道：香火練制不易，不能隨便於人，虔誠奉獻者方能得之。\n",
		"凌虛道長説道：紅松和青柏都是煉製香火的好材料。\n",
		"凌虛道長説道：制香材料是從林子裏砍伐而來。\n",
		"凌虛道長説道：武當的松林和柏林都長了幾百年了，還沒有人走通過。\n",
		"凌虛道長説道：砍樹的時候要多加小心，我派出砍樹的道士，有些就有去無回。\n",
	}) );
	set("wanted", ({ HIR"紅松樹幹"NOR, HIG"青柏樹幹"NOR }));
	create_family("武當派", 3, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}

void init()
{
	object me = this_player();
	
	::init();
	if( interactive(me) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	mapping myfam;
	object where, ob;

	ob = this_object();
	myfam = (mapping)me->query("family");
	where = environment(ob);

	if( !me || !living(ob) ||
		strsrch(file_name(where), "/d/wudang/") < 0 ||
		environment(me) != environment() )
		return;
	if ( (string)me->query("wdjob/supervisor") == "凌虛道長" )
	{
		me->set_temp("apply/short", 
			({ HIW"武當伐木　"NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
		message_vision("凌虛道長盯住$N：我託你去找的" + me->query("wdjob/object") +"可有着落了？\n", me);
	}
	else
		if ( myfam && myfam["family_name"] == "武當派" )
		{
			if ( me->query("wudang/offerring") < me->query("age") )
				message_vision("凌虛道長對着$N怒斥道：你疏於敬奉，離被逐出山門不遠了！\n", me);
			else if ( me->query("wudang/offerring") <
					me->query("age")*4/3)
				message_vision("凌虛道長對着$N語重心長：凡我武當弟子，都應勤勉奉獻，"+RANK_D->query_respect(me)+ "要加強努力啊！\n",me);
			else if ( me->query("wudang/offerring") <
					me->query("age")*2)
				message_vision("凌虛道長對$N説道：" + RANK_D->query_respect(me) + "能盡職貢奉，眾道長對你很滿意。\n", me);
			else message_vision("凌虛道長指着$N讚歎道：" + RANK_D->query_respect(me) + "勤於敬奉，真乃我輩楷模也！\n", me);
		}
		else if ( me->query("title") == "武當道童" ) 
			message_vision("凌虛道長對着$N説道：繼續努力，爭取早日入我山門。\n", me);
		else if ( me->query("wudang/offerring") > me->query("age")*2 ) 
			message_vision("凌虛道長對着$N問候道：原來是大香客到了！失迎、失迎！\n", me);
		else if ( me->query("wudang/offerring") > me->query("age") ) 
			message_vision("凌虛道長對着$N問候道：這位香客請了！\n", me);
		else 
		{
			me->set("wudang/yuzhen_block", 1);
			say("凌虛道長説道：如不是敬香，請勿上山！\n");
		}
}

string ask_job()
{
	object ob;
	string what;
	string *wanted;

	ob = this_player();

	if ( ob->query("wdjob/supervisor") )
	{
		command("say 你第一份活兒都沒做完就想做第二份？");
		if ( ob->query("wdjob/supervisor") == "凌虛道長") 
		{
			add_action("do_say", "say");
			return("如果你幹不了我派給你的活，可以直接跟我説你幹不了。");
		}
		return ("如果你幹不了，可以直接去告訴"+ob->query("wdjob/supervisor"));
	}
	if (query_temp("stock") > 10)
		return ("你來晚了，今天的活兒我都分派完了。");
	add_temp("stock", 1);
	wanted = query("wanted");
	what = wanted[random(sizeof(wanted))];

	ob->set("wdjob/supervisor", "凌虛道長");
	ob->set("wdjob/object", what);
	ob->set("wdjob/description", what);
	ob->set("wdjob/wage", 3);
	ob->set_temp("apply/short", ({ HIW"武當伐木　"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
	message_vision("凌虛道長高興對$N説道：來得正好，這裏正缺人手！\n", ob);
	return ("我需要"+ what +CYN"造香用，你去給我砍些來吧！\n");
}

int accept_kill(object obj)
{
	object ob=this_object();
	if (obj->is_killing(this_object()) ) return 1;
	if ( obj->query("wdjob/supervisor") == "凌虛道長" )
	{
		message_vision("$N想殺掉$n。\n$n厲聲對$N道：你想造反哪？！報酬扣消。\n", obj, ob);
		obj->set("wdjob/wage", 0);
		return 0;
	}
	else if ( obj->query("family/family_name") == "武當派" )
	{
		message_vision("$N想殺掉$n。\n$n厲聲對$N道：你我本同門，卻為何想相害於我！\n$n對$N很不滿意！\n", obj, ob);
		obj->add("wudang/offerring", -20);
		return 0;
	}	
	else
	{
		command("family 各位武當同門，" + obj->name() + "這個" + RANK_D->query_rude(obj) + "膽敢在武當撒野，大夥兒一起跟我上！");
	  return 1;
	}
}

int accept_object(object who, object ob)
{

	object obn, wage;
	int i, j, k;
	string *wanted;


	if (ob->query("money_id") && ob->value() >= 100*(int)who->query("age") )
	{
		if ((string)(who->query("family/family_name")) == "武當派") 
			tell_object(who, "凌虛道長哈哈一笑：既然道"+(((string)who->query("gender")=="女性")?"姑":"兄")+"如此誠心向道，我這有新制香火一枝，請拿去貢奉吧。\n");
		else
			tell_object(who, "凌虛道長哈哈一笑：既然施主如此誠心向道，我這有新制香火一枝，請施主拿去貢奉吧。\n");
		obn = new("/d/wudang/obj/incense");
		obn->move(who);
		return 1;
	}
	else
		if (ob->query("money_id") )
		{
			if((string)(who->query("family/family_name"))=="武當派")
				tell_object(who, "凌虛道長對你讚歎道：武當山香火鼎盛，全靠象道"+(((string)who->query("gender")=="女性")?"姑":"兄")+"你這樣捐獻香火啊！\n");
			else
				tell_object(who, "凌虛道長對你讚歎道：武當山香火鼎盛，全靠象您這樣的虔誠香客啊！\n");

			return 1;
		}
		else if (((string)who->query("wdjob/supervisor")=="凌虛道長") &&
				(string)who->query("wdjob/object") ==
				(string)ob->query("name") )
		{
			i = (int)who->query("wdjob/wage");
			if (i < 0 || i >= 13) i = 2;

			wage = new("/clone/money/silver");
			wage->set_amount(i);
			wage->move(who);

			command("say 有勞這位"+RANK_D->query_respect(who)+"了。");
			command("thumb " + who->query("id"));
			message_vision("凌虛道長給$N"+chinese_number(i)+"兩白銀作為工作報酬。\n", who);

			who->add("combat_exp", 1+random(i));
			who->add("wudang/offerring", 1+random(i/4));
			who->delete_temp("apply/short");
			who->add("wdjob/succeed", 1);
			who->delete("wdjob/supervisor");
			who->delete("wdjob/description");
			who->delete("wdjob/wage");
			who->delete("wdjob/object");

			return 1;
		}
		else if( (int)member_array((string)ob->query("name"), (string *)query("wanted")) != -1 )
		{
			if ( query_temp("stock") > 10 )
			{
				say("凌虛道長搖搖頭説：多謝這位" +RANK_D->query_respect(who)+"，可是我要的材料都已經有着落了。\n");
				return 1;
			}
			message_vision("凌虛道長高興對$N説道：來得正好，這正是我所需要的！\n", who);
			add_temp("stock", 1);
			who->add("wudang/offerring", random(1));
			i = (int)who->query("wdjob/wage");
			j = who->query("wudang/offerring")-who->query("age")*2; 
			if ( (who->query("family/family_name") == "武當派" ) && 
				(j > 0 ) )
			{
				who->add("combat_exp", (j+i)/2 + random(i+j));
				k = j/2 + random(i);
				who->add("potential", k);
				if ( random(2) ) 
				{
					tell_object(who, "我這有新制香火一枝，你拿去貢奉吧。\n");
					who->add("wudang/offerring", -1-random(3));
					obn = new("/d/wudang/obj/incense");
					obn->move(who);
				}
			
			}
			else if ( who->query("family/family_name") == "武當派" )
			{
				who->add("combat_exp", i/2+random(i));
				k = 1+random(i);
				who->add("potential", k);
			}
			else who->add("combat_exp", 1+random(i));
			command("say 你如此自願為武當效力，日後必成武當棟樑！");
			command("thumb " + who->query("id"));
			return 1;
		}
	return 0;
}


int do_say(string arg)
{
	object ob, who;

	who = this_player();
	ob = this_object();

	if ( (string)arg != "幹不了") return 0;
	if ( who->query("wdjob/supervisor") != ob->query("name")) return 0;

	message_vision("$N低聲説道：道長分派的活我幹不了…\n", who);
	command("pat "+ who->query("id"));
	command("say 沒關係，下次好好幹！");

	this_object()->add_temp("stock", -1);
	who->delete_temp("apply/short");
	who->add("wdjob/fail", 1);
	who->delete("wdjob/supervisor");
	who->delete("wdjob/description");
	who->delete("wdjob/wage");
	who->delete("wdjob/object");

	return 1;
}
