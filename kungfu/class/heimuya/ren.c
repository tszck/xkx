// ren.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("任我行", ({ "ren woxing", "ren","woxing" }));
	set("long", "只見他一張長長的臉孔，臉色雪白，更無半分血色，眉目清秀，
身材甚高，一頭黑髮，穿的是一襲青衫。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("no_get", 1);
	set("bihua", 10);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
 	set("jiali", 400);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);         // 讀書識字
	set_skill("force", 200);            // 基本內功
	set_skill("finger", 200);           // 基本指法
	set_skill("unarmed", 200);          // 基本拳腳
	set_skill("dodge", 200);            // 基本躲閃
	set_skill("parry", 200);            // 基本招架
	set_skill("dagger", 200);           // 基本刺法
	set_skill("sword", 200);            // 基本劍法
        set_skill("shigu-bifa", 200);       // 石鼓打穴筆法
	set_skill("piaoyibu", 200);         // 飄逸步法
	set_skill("wuyun-jian", 200);       // 五韻七絃劍
	set_skill("xuantian-zhi", 200);     // 玄天無情指
	set_skill("kuihua-xinfa", 200);     // 葵花心法
	set_skill("xixing-dafa", 200);      // 吸星心法
	set_skill("changquan", 200);        // 太祖長拳
	set_skill("damo-jian", 200);        // 達摩劍法
	set_skill("taiji-jian", 200);       // 太極劍法
	set_skill("huifeng-jian", 200);     // 迴風拂柳劍
	set_skill("taishan-sword", 200);    // 泰山劍法
	set_skill("hengshan-jian", 200);    // 恆山劍法
	set_skill("hengshan-sword", 200);   // 衡山劍法
	set_skill("huashan-sword", 200);    // 華山劍法
	set_skill("songshan-sword", 200);   // 嵩山劍法

	map_skill("force", "xixing-dafa");
	map_skill("sword", "wuyun-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "damo-jian");
	prepare_skill("finger", "xuantian-zhi");

        set("inquiry", ([
                "比劍" :  (: ask_bijian :),
                "劍法" :  (: ask_bijian :),
                "黑木令" : "要拿黑木令？老夫想先看看你的劍法！\n",
		"日月神教" : "你想加入我日月神教，就得找四大堂長老。",
		"入教"     : "你想加入我日月神教，就得找四大堂長老。",
	]) );

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"第七代教主"NOR);
	create_family("黑木崖", 7, "弟子");
 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_bijian()
{
	object weapon, obj, me = this_player(), ob = this_object();
 

        if (!objectp(weapon = ob->query_temp("weapon")))
	{
		weapon = new("/clone/weapon/changjian");
		weapon -> move(ob);
		command("wield sword");
	}
	if(query("bihua") < 0)
	{
		message_vision("$N躬身説道：“晚輩今日有幸拜見任老前輩，還望多加指教。”\n$n冷笑道：“江南四狗怎麼不敢進來見我？！”\n", me, ob );
		return 1;
	}
	add("bihua", -1);
	message_vision("$N躬身説道：“晚輩今日有幸拜見任老前輩，還望多加指教。”\n$n笑道：“不用客氣，你來解我寂寞，可多謝你啦。”\n", me, ob );
	message_vision("$N道：“不敢。”\n$n點了點頭，説道：“我只想瞧瞧你的劍法，並非真的過招，再説，我也未必能勝得了你。”\n\n", me, ob);
        command("xkx 老子劍法天下第一，找我比劍？找死!");
	command("enable sword damo-jian");
	say(HIR"任我行大喝一聲：“少林劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才一招。”\n");
		return 1;
	}
	command("enable sword taiji-jian");
	say(HIR"任我行大喝一聲：“武當劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才兩招。”\n");
		return 1;
	}
	command("enable sword huifeng-jian");
	say(HIR"任我行大喝一聲：“峨嵋劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才三招。”\n");
		return 1;
	}
	command("enable sword songshan-sword");
	say(HIR"任我行大喝一聲：“嵩山劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才四招。”\n");
		return 1;
	}
	command("enable sword taishan-sword");
	say(HIR"任我行大喝一聲：“泰山劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才五招。”\n");
		return 1;
	}
	command("enable sword huashan-sword");
	say(HIR"任我行大喝一聲：“華山劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才六招。”\n");
		return 1;
	}
	command("enable sword hengshan-sword");
	say(HIR"任我行大喝一聲：“衡山劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“才七招。”\n");
		return 1;
	}
	command("enable sword hengshan-jian");
	say(HIR"任我行大喝一聲：“恆山劍法！”"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if( (int)me->query("qi") < 0 || !present(me, environment()))
	{
		say("任我行嘆了口氣，説道：“還是沒過八招。”\n");
		return 1;
	}

	obj = new("/d/heimuya/obj/heimu-ling");
	obj -> move(me);
	me -> set_temp("renwoxing/bijian", 1);
	say("任我行説道：“這位" + RANK_D->query_respect(me)+"不錯，我就送你一塊黑木令吧。”\n");
	return 1;
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂長老入教去！\n");
		return;
	}
	if (ob->query("betrayer"))
	{
		command("say 我是不收叛徒的。");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 150)
	{
		command("say 我是不輕易收徒的。");
		command("say 在我教的內功上，" + RANK_D->query_respect(ob) +
			"是否還應該多下點功夫？");
		return;
	}
	if (ob->query_temp("renwoxing/bijian"))
	{
		ob->delete_temp("renwoxing/bijian");
		if ( ob->query("kar") == this_object()->query("kar"))
		{
			command("say 好吧，既然你我如此投緣，老夫就收下你了。");
                        command("xkx 老夫收得如此良徒，東方不敗小兒你的報應來拉!");
			command("recruit " + ob->query("id"));
		}
		else
		{
			message_vision(
"$N拍着胸膛道：“任老先生，你一世英雄了得，何苦在這地牢之中和腐
土同朽？只須你答允收我為徒，在下言出如山，自當助你脫困。我想老
先生經過一番比劍，當年的豪情勝概，不免在心中又活了起來罷？外邊
天地多麼廣闊，你老爺子出得黑牢，普天下的男女老幼，你要殺哪一個
便殺哪一個，無人敢與老爺子違抗，豈不痛快之極？”\n", ob);
			command("say 哼，我才不上你的當呢。");
		}
	}
	else
		command("say 好吧，我先看看你的劍法吧。");
}
