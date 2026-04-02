// Last Modified by winder on Feb. 28 2001
// yangguo.c 楊過

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("楊過", ({"yang guo", "yang", "guo"}));
	set("nickname", HIB"神鵰大俠"NOR);
	set("gender", "男性");
	set("age", 26);
	set("long",
	"他就是神鵰大俠楊過，一張清癯俊秀的臉孔，劍眉入鬢，鳳眼生威。\n"
	"雖然他只有一隻胳膊，但是魁偉的身材仍讓人感覺英氣逼人。\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("chat_chance", 1);
	set("chat_msg", ({
		"楊過嘆了口氣道：“不知龍兒現在可好？十六年了，她一直在哪裏？”\n", 
		"楊過喃喃道：“獨孤求敗！獨孤求敗！求一敗而不可得？”\n", 
	}));
	set("chat_chance_combat",50);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.anran" :),
		(: command("wield jian") :),
		(: command("unwield jian") :),
	}));

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("yunv-xinfa", 200);
	set_skill("sword", 200);
	set_skill("yunv-jian", 200);
	set_skill("quanzhen-jian",200);
	set_skill("dodge", 200);
	set_skill("anran-zhang",220);
	set_skill("yunv-shenfa", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("meinv-quan", 200);
	set_skill("literate",120);
	set_skill("qufeng",120);
	set_skill("tanzhi-shentong",200);
	set_skill("iron-sword",200);
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "iron-sword");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "anran-zhang");

	create_family("古墓派", 4, "弟子");
	set("letter_count", 1);

	set("inquiry", ([
		"龍兒"     :(: ask_me :),
		"小龍女"   :"你知道我龍兒的下落？\n",
		"玉女劍法" :"玉女劍法和全真劍法合壁，天下無敵！\n",
		"古墓派"   :"我的林祖師爺爺本來和重陽先師是一對璧人，可是...\n",
		"郭靖"     :"我郭伯父是當世一代大俠。\n",
		"黃蓉"     :"我郭伯母確實是算無遺策。\n",
		"雕兄"     :"雕兄既是我師，亦復我友。\n",
		"神鵰"     :"你問雕兄？\n",
		"玄鐵劍"   :"玄鐵劍在獨孤劍冢。\n",
		"獨孤劍冢" :"獨孤劍冢嘛，自己找吧。\n",
	]) );
	set("env/wimpy", 40);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] != "古墓派") return;
	if ((int)ob->query_temp("marks/小龍女") == 1 )
	{
		if (ob->query_int() < 40)
		{
			message_vision("楊過看了看$N說道：看你笨頭笨腦的，還是先去讀點書吧。\n", ob);
			return;
		}
		if (ob->query_skill("yunv-xinfa",1) < 150)
		{
			message_vision("楊過看了看$N說道：你的本門心法還差點火候，再努力一把吧。\n", ob);
			return;
		}
		if (ob->query_skill("yunv-jian",1) < 150)
		{
			message_vision("楊過看了看$N說道：你的本門劍法還差點火候，再努力一把吧。\n", ob);
			return;
		}
		if (ob->query_skill("quanzhen-jian",1) < 150)
		{
			message_vision("楊過看了看$N說道：你的全真劍法還差點火候，再努力一把吧。\n", ob);
			return;
		}
//message_vision("楊過嘆了口氣，看看$N，說道：你沒找到我的龍兒麼？\n", ob);
		command("say 好吧，我就收下你這個徒弟了。\n");
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("楊過嘆了口氣，看看$N，說道：你沒找到我的龍兒麼？\n", ob);
		return;
	}
}

int accept_object(object me, object ob)
{
	object obn;
	if ( (string) ob->query("id") =="junzi jian" )
	{
		message_vision("楊過說道：這位"+ RANK_D->query_respect(me)+"，我實在高興你帶來我的龍兒的信物，她現在好嗎？\n",me);
		if(query("letter_count") > 0)
		{
			message_vision("楊過又對$N說道：麻煩你幫我把信交給她，告訴她我等她等了十六年了，帶她來我這裏。\n" , me);
			obn=new("/d/gumu/npc/obj/letter");
			obn->move(me);
			add("letter_count", -1);
		}
		return 1;
	}
	return 0;
}

string ask_me()
{
	object me=this_player();
	if(present("junzi jian",this_object()))
		return "多謝你的關心啦，我已經有龍兒的消息了。\n";
	else
	{
		me->set_temp("mark/楊",1);
		return "你有龍兒的消息嗎？\n";
	}	
}

