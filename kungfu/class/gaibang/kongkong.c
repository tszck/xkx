// kongkong.c 空空兒

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	seteuid(getuid());
	set_name("空空兒", ({ "kong kong","beggar","qi gai","kong" }) );
	set("nickname", "妙手神丐");
	set("gender", "男性" );
	set("age", 53);
	set("long", "一個滿臉風霜之色的老乞丐。\n");
	set("attitude", "peaceful");
	set("class", "beggar");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);

	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);

	set("startroom","/d/city/lichunyuan");
	set("thief", 0);
	set("combat_exp", 50000);

	set_skill("force", 40); 
	set_skill("hand", 40);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("stealing", 100);
	set_skill("begging", 100);
	set_skill("checking", 80); 
	set_skill("huntian-qigong", 40); 
	set_skill("suohou-hand", 40);
	set_skill("xiaoyaoyou", 50); 
	set_skill("training", 30);
	set_skill("strike",70);

	set_skill("lianhua-zhang",70);
	set_skill("lvshuang-bingzhi",70);
	map_skill("strike","lvshuang-bingzhi");
	prepare_skill("strike", "lvshuang-bingzhi");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");

	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", HIG"八袋護法"NOR);
	set("party/level", 8);
	create_family("丐幫", 19, "弟子");

	set("chat_chance", 20);
	set("chat_msg", ({
		"空空兒説道：好心的大爺哪～ 賞我要飯的幾個銅板吧～\n",
		"空空兒懶洋洋地打了個哈欠。\n",
		"空空兒伸手捉住了身上的蝨子，罵道：老子身上沒幾兩肉，全叫你們給咬糜了。 \n",
		(: random_move :)
	}) );
	setup();

	carry_object(FOOD_DIR+"jitui");
	carry_object(LIQUID_DIR+"jiudai");
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
		"能好好學習本門武功，將來在江湖中闖出一番作為。");
	command("recruit " + ob->query("id"));
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() ||
		((fam = ob->query("family")) && fam["family_name"] == "丐幫") ||
		(int)ob->query_skill("taoism", 1) > 30 || 
		ob->query_int() > 30) return;

	switch( random(5) )
	{
		case 0:
			command("hehe " + ob->query("id"));
			command("beg coin from " + ob->query("id"));
			command("buy jitui");
			break;
		case 1:
			command("grin " + ob->query("id"));
			command("steal silver from " + ob->query("id"));			
			command("eat jitui");
			break;
		case 2:
			command("hi " + ob->query("id"));
			command("steal gold from " + ob->query("id"));			
			command("drink jiudai");
			break;
		case 3:
			command("pat " + ob->query("id"));
			command("beg jiudai from " + ob->query("id"));	
			command("eat jitui");
			break;
		case 4:
			command("walkby " + ob->query("id"));
			command("beg jitui from " + ob->query("id"));	
			command("drink jiudai");
			break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
		command("smile");
		command("say 多謝啦！其實我還是有點錢的，這次只不過試試你罷了！");
		command("give 10 silver to " + me->query("id"));
	}
	else
	{
		command("shake");
		command("say 這種東西鬼才要！滾一邊去！");
		command("give " + obj->query("id") + " to " + me->query("id"));
//		obj->move(this_player());
	}

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饒命~~小的這就離開~~\n");
	return 0;
}
