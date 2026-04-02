// wg_zongguan.c 武館總管

#include <ansi.h>

inherit NPC;
string *names = ({"打掃馬房","鋸木頭","劈柴","澆菜地","鋤草","挑水",});
string ask_job();

void create()
{
	set_name("張風", ({ "zhang feng","zhang","feng", "zongguan" }));
	set("title", "揚州武館總管");
	set("gender", "男性");
	set("age", 45);
	set("str", 27);
	set("dex", 26);
	set("int", 20);
	set("con", 20);
	set("per", 16);
	set("long", "這人相貌和藹，笑呵呵的，一手拿個旱菸袋。\n");
	set("combat_exp", 700000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set_skill("unarmed", 120);
	set_skill("force", 130);
	set_skill("strike", 160);
	set_skill("hammer", 100);
	set_skill("kunlun-strike", 160);
	set_skill("xuantian-wuji", 160);
	set_skill("kunlun-shenfa", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "kunlun-strike");
	map_skill("force", "xuantian-wuji");
	map_skill("strike", "kunlun-strike");
	prepare_skill("strike","kunlun-strike");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
	set("inquiry", ([
		"工作" : (: ask_job :),
		"job" : (: ask_job :),
		"工具" : "你去物品房找老李要吧！",
	]));
	setup();
	carry_object("clone/cloth/cloth")->wear();

}

void init()
{
	object ob;
	::init();

	if (interactive(ob = this_player()) && !is_fighting() && !wizardp(ob))
	{
		if((int)ob->query("combat_exp") > 100000) return;
		else
		{
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}
	add_action("do_job","job");
}
string ask_job()
{
	object me, ob;
	string target;
	ob=this_player();
	me=this_object();

	target = names[random(sizeof(names))];
	if (ob->query_temp("job_name"))
		return ("你不是已經領了工作嗎？還不快去做。\n");
	if (ob->query("combat_exp") >= 100000)
		return ("你功夫已經足夠闖蕩江湖，這裏沒有什麼適合你的工作了。\n");
	ob->set_temp("job_name",target);
	ob->apply_condition("wuguan_job",random(3)+4);
	return "正好現在有好多事要做，你先去東物品房領工具，然後去後院"+ target+ "吧。";
}
int do_job(string arg)
{
	int add_exp,add_pot,exp,pot;
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!arg || arg!="ok") return 0;

	if(!ob->query_temp("job_name"))
		return notify_fail("沒給你工作，你怎麼跑來覆命了？\n");
	if (interactive(ob) && (int)ob->query_condition("wuguan_job"))
	{
		command("hmm "+ob->query("id"));
		return notify_fail(RED "你這麼快回來了，是不是還沒做完啊，吩咐你回來了嗎？"NOR);
	}
	if(!ob->query_temp("mark/還了"))
		return notify_fail("你先把工具還到老李那再來覆命吧。\n");

	if(!(ob->query_temp("mark/劈完了") || 
		ob->query_temp("mark/澆完了") ||
		ob->query_temp("mark/鋤完了") ||
		ob->query_temp("mark/鋸完了") ||
		ob->query_temp("mark/掃完了") ||
		ob->query_temp("mark/挑完了")))
		return notify_fail("你偷懶啊，叫你幹活你不去幹，跑來領功！\n");

	command("smile "+ob->query("id"));
	command("say 好，"+RANK_D->query_respect(ob)+"，做得好，這是給你的獎賞！");
	if (random(10)<7)
	{
		me->add_money("coin",(int)(ob->query_skill("force",1)/2)+65);
		command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/2)+50)+" coin");
	}
	else
	{
		me->add_money("silver",(int)(ob->query_skill("force",1)/5)+1);
		command("give "+ob->query("id")+" "+((int)(ob->query_skill("force",1)/5)+1)+" silver");
	}
	add_pot=50 + random(50) + (int)(ob->query_skill("force",1)/10);
	add_exp=100 + random(100) + (int)(ob->query_skill("force",1)/5) ;	
	exp=(int)ob->query("combat_exp");
	pot=(int)ob->query("potential");
	exp= exp + add_exp;
	pot= pot + add_pot;
	ob->set("combat_exp",exp);
	ob->set("potential",pot);
	tell_object(ob,HIW"你得到了:"
		+ chinese_number(add_exp) + "點實戰經驗，"
		+ chinese_number(add_pot) + "點潛能，\n"NOR);
	ob->delete_temp("job_name");
	ob->delete_temp("mark");
	ob->set_temp("prize_reason","武館");
	ob->set_temp("can_give_prize",1);
	ob->set_temp("prize_exp",add_exp);
	ob->set_temp("prize_pot",add_pot);
	return 1;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ||
		ob->query_temp("job_name") || ob->query("combat_exp") > 1000 )
		return;

	command("bow "+ob->query("id"));
	command("say 這位"+RANK_D->query_respect(ob)+"，我們這缺人手，你可以找我領工作來做。\n");
}

