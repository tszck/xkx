//Edited by fandog, 01/31/2000

inherit NPC;
#include <ansi.h>

int ask_skill1();
int ask_skill2();
void create ()
{
	set_name("丁典", ({"ding dian","ding","dian"}));
	set("long", "
這人滿臉虯髯，頭髮長長的直垂至頸，衣衫破爛不堪，簡直如同荒山中
的野人。手上手銬，足上足鐐，琵琶骨中穿着兩條鐵鏈。他臉上、臂上、
腿上，都是酷遭鞭打的血痕。\n");
	set("gender", "男性");
	set("age", 30);
	set("combat_exp", 5000000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("per", 24);

	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("yanfly", 200);
	set_skill("shenzhao-jing", 300);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "shenzhao-jing");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "yanfly");
	set("chat_chance", 10);
	set("chat_msg", ({
"丁典輕輕嘆了一口氣。那嘆息中，竟有憂傷、溫柔之意。\n",
"丁典嘴角掛着一絲微笑，癡望遠處高樓紗窗上那一盆鮮花。\n",
"丁典大聲道：怎麼會忘記？決不會的！難道……難道是生了病？\n",
"丁典喃喃道：就算是生了病，也會叫人來換花啊！\n",
}) );
	set("inquiry", ([
		"凌霜華" : "“唉……”，然後指了指牢外那座小樓的窗口，啥也不說了。\n",
		"喚醒"   : (: ask_skill1 :),
		"療精"   : (: ask_skill2 :),
	]));

	setup();
	carry_object("/d/jiangling/obj/qiuyi")->wear();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/丁"))
		return 0;
	ob->add_temp("mark/丁", -1);
	return 1;
}

int accept_object(object who, object ob)
{
 
	if (!(int)who->query_temp("mark/丁"))
		who->set_temp("mark/丁", 0);
	if (ob->query("id") == "green flower")
	{
		message_vision("看來$N有望得到丁典指點一些武功的問題。\n",who);
		who->add_temp("mark/丁", 1000);
		return 1;
	}
}

int ask_skill1()
{
 
	object who = this_player();
	
	if (!who->query_temp("mark/丁")) return 0;
	if (!who->query_skill("shenzhao-jing",1)) return 0;
	if (who->query("can_perform/shenzhao-jing/wakeup")) return 0;
	if (who->query_skill("shenzhao-jing",1) < 100)
	{
		command("say 你的神照經功力還不夠高，多學學吧。");
		return 1;
	}
	command("sign");
	command("say 不知你學得神照經是福是禍了。也罷，隨你去吧。");
	tell_object(who,HIC"丁典在你耳邊悄悄說了幾句運功的口訣，你急忙用心一一記下。\n"NOR);
	tell_object(who,HIC "你學會了「喚醒」。\n" NOR);
	who->set("can_perform/shenzhao-jing/wakeup",1);
	return 1;
}
int ask_skill2()
{
 
	object who = this_player();
	
	if (!who->query_temp("mark/丁")) return 0;
	if (!who->query_skill("shenzhao-jing",1)) return 0;
	if (who->query("can_perform/shenzhao-jing/jingheal")) return 0;
	if (who->query_skill("shenzhao-jing",1) < 50)
	{
		command("say 你的神照經功力還不夠高，多學學吧。");
		return 1;
	}
	command("sign");
	command("say 不知你學得神照經是福是禍了。也罷，隨你去吧。");
	tell_object(who,HIC"丁典在你耳邊悄悄說了幾句運功的口訣，你急忙用心一一記下。\n"NOR);
	tell_object(who,HIC "你學會了「療精」。\n" NOR);
	who->set("can_perform/shenzhao-jing/jingheal",1);
	return 1;
}