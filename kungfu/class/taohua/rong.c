// /kungfu/class/taohua/rong.c 黃蓉

#include <ansi.h>
#include "game.h"

inherit NPC;
inherit F_MASTER;

string ask_chicken();
int ask_jiuyin();
int ask_game();

void create()
{
	set_name("黃蓉", ({"huang rong", "huang", "rong"}));
	set("gender", "女性");
	set("age", 18);
	set("long", "這是桃花島主的獨生女兒。由於島主夫人早死，島主對這個女兒備加疼愛。她生性跳脫飛揚，喜歡四處亂跑。\n");

	set("attitude", "peaceful");
	set("class", "scholar");
	set("per", 30);
	set("str", 18);
	set("int", 30);
	set("con", 21);
	set("dex", 26);

	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);
	
	set("combat_exp", 200000);
	set("score", 0);
	set("jiacount", 1);
	set("env/wimpy", 60);
	
	set_skill("force", 60);
	set_skill("bibo-shengong", 80);
	set_skill("unarmed", 80);
	set_skill("xuanfeng-leg", 80);	  // 旋風掃葉腿
	set_skill("strike", 80);			// 基本掌法
	set_skill("luoying-zhang", 80);
	set_skill("dodge", 150);
	set_skill("anying-fuxiang", 100);
	set_skill("parry", 85);
	set_skill("literate",150);		   // 讀書識字
	set_skill("sword", 80);
	set_skill("luoying-shenjian",80);
	
	map_skill("force"  , "bibo-shengong");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("sword"  , "luoying-shenjian");
	
	create_family("桃花島", 2, "弟子");

	set("inquiry", ([
		"黃藥師" : "爹爹呀, 不在廳裏麼? ",
		"郭靖"   : "怎麼? 你有我靖哥哥的消息嗎? ",
		"洪七公" : "師父他老人家就喜歡喫叫化雞! ",
		"叫化雞" : (: ask_chicken :),
		"九陰真經經義" : (: ask_jiuyin :),
		"遊戲"   : (: ask_game :),
	]) );

	setup();
	carry_object(__DIR__"obj/ruanwei")->wear();
	carry_object(__DIR__"obj/shudai")->wear();
}

init()
{
	object ob;
	mapping myfam;
		
	::init();
	add_action("do_kiss", "kiss");
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if ((!myfam || myfam["family_name"] != "桃花島") &&
			(!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying",2,ob);
		}
	}
}
int do_kiss ( string arg )
{
	object ob = this_player () ;
	if( !arg || arg!="rong" ) return 0;
   
	if ( (string) ob -> query ("gender") == "男性" )
		command("say 來人！救命啊！"+ob->query("name")+"要非禮我！\n");
	else
		message_vision("\n黃蓉對$N笑道：“好姐姐不要這樣，我怕癢！”\n", ob);
	return 1 ;
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	if ((string)ob->query("gender") == "男性")
		message_vision("\n黃蓉面現驚奇之色，打量了$N一眼，説到：“你是什麼人，竟敢亂闖我的閨房？\n再不滾出去，看我怎麼整你！”\n", ob);
	else
		message_vision("\n黃蓉看了看$N，説到：“好久沒生人來過了，不知這位姐姐可有我靖哥哥的消息？\n", ob);
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_temp("marks/蓉兒")==1)
	{
		say( "黃蓉一臉笑意：“多謝你帶來靖哥哥的口信！”\n");
		if (query("jiacount")== 1)
		{
			say( "黃蓉輕輕一笑：我不收徒的..可也不能讓你白來，這軟猥甲就送給你吧。\n");
			new("/kungfu/class/taohua/obj/ruanwei")->move(ob);
			tell_object(ob,"黃蓉從身上脫下一件軟猥甲遞給你。\n");
			ob->set_temp("marks/蓉兒",2);
			set("jiacount", 0);
		}
	}
	else
		command("say 我年紀這麼小就收徒弟，豈不讓人笑掉大牙！");
}

string ask_chicken()
{
	if (this_player()->query_temp("marks/雞", 1))
		return "你這個人怎麼這麼煩？老説車軲轆話！\n";
	else
	{
		say("蓉兒神往地説：叫化雞可是杭州著名特產，我爹當年費了好大的勁才搞到了製作\n"
			"它的祕方。你問它來幹什麼？\n");
		this_player()->set_temp("marks/雞", 1);
		return "你可以出去了。\n";
	}
}

int ask_jiuyin()
{
	object me = this_player();
	
	if(me->query("family/family_name")=="白駝山派" && !me->query("reserve")
		&& me->query("family/master_id") == "ouyang feng" )
	{
		if(me->query("combat_exp")>500000 && present("mask_jiuyin",me))
		{
			destruct( present("mask_jiuyin", me) );
			message_vision(HIY "黃蓉眼中閃過一絲狡黠的神色：“你想知道真經的解釋麼？好吧，我説給你聽便是。”\n", me);
			message_vision("説罷，接過$N手中的經書，輕輕唸了起來：\n", me);
			message_vision("“「忽不爾，肯星多得，斯根六補」這是「善用觀相，運作十二種息」的意思。\n", me);
			message_vision("「吉爾文花思，哈虎」嗯....這個該作「能愈諸患，漸入神通」解...”\n", me);
			message_vision(HIG "$N大為興奮，忙凝神傾聽，內息早於不知不覺中按照黃蓉所解之法四處遊走......\n", me);
			message_vision("$N的神智漸漸迷糊起來，忽而抓耳撓腮，忽而側頭苦思，種種怪狀，令人不解。\n", me);
			message_vision("突然間，$N反手啪啪啪連打自己三個耳光，雙手撐地，倒立了起來，全身真氣逆遊亂走 \n"NOR, me);
			if (random(5) == 3)
			{
				tell_object(me,"過了半晌，你只覺得全身經脈運行方式大為異常，略一提氣，發現陰維，陽維，陰嶠， \n");
				tell_object(me,"陽嶠四脈頗有逆行之勢，不由得又驚又喜。\n");
				me->set("reserve", 1);
				me->add("eff_jing", -100);
				me->add("max_neili", -2);
			} else {
				tell_object(me,"過了半晌，你心中一團亂麻，渾身乏力，頭痛欲裂。一聲嘶吼，暈了過去...\n");
				me->add("eff_jing", -100);
				me->add("max_neili", -2);
				me->unconcious();
			}
			return 1;
		} else  return notify_fail("黃蓉白了你一眼：“就你這點微末道行，想學九陰真經？也不怕被人笑掉大牙麼？”\n");
	} else return 0;
}

int ask_game()
{
	object me = this_player();
	object ob = this_object();

	if (me->query_temp("match_game/playing")) {
		write("你已經在玩遊戲了。\n");
		return 1;
	}
/*	if (me->query_temp("match_game/lost")) {
		message_vision( "$n仰起頭不屑的對$N説道：你太笨了，我才不跟你玩呢。\n", me, ob );
		return 1;
	}*/
	if (me->query_temp("match_game/win")) {
		message_vision( "$n點了點頭道：好吧！上次僥倖讓你贏了，這回你就沒這麼好運氣了。\n", me, ob );
		me->delete_temp("match_game/win");
	}
	else
		message_vision( "$n眉頭一揚，對$N説到：好啊，看看你到底有多聰明。\n", me, ob );
	return play_game(me,ob);
}
