// Last Modified by winder on Apr. 25 2001
//tianshaxing.c

#include <ansi.h>
inherit NPC;
void copyto(object ob);
void create()
{
	set_name("天殺星", ({"tian shaxing" ,"tian"}));
	set("gender", "男性");
	set("age", 40);
	set("long", "他是七殺門的首領。\n");
	set("per", 10);
	set("attitude", "peaceful");
    //  seteuid(getuid());

	set("str", 25);
	set("int", 35);
	set("con", 35);
	set("dex", 35);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 150);

	set("combat_exp", 8000000);
	set("score", 0);
	set("shen_type", 0);

	set_skill("force", 250);
	set_skill("taiji-shengong", 300);
	set_skill("unarmed", 250);
	set_skill("taiji-quan", 300);
	set_skill("dodge", 250);
	set_skill("tiyunzong", 300);
	set_skill("sword", 250);
	set_skill("taiji-jian", 300);
	set_skill("parry", 250); 
	map_skill("force", "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	create_family("七殺門", 1, "殺手");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
	}));   
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
  object shu=present("zhan shu",this_player());
  if (shu && shu->is_zhanshu())
    set("pk_target",this_player());

	if ( living(this_object())  &&
	   interactive(ob=this_player()) && 
     ob==query("pk_target") )
			{
				remove_call_out("killing");
				call_out("killing", 0, ob);
			}
	if (query("inited")) return;
	remove_call_out("dest");
	call_out("dest",600);
  set("inited",1);
}

void dest()
{
	object ob=this_object();
	if ( !living(ob) || ob->is_busy() || ob->is_fighting() )
	{
		remove_call_out("dest");
		call_out("dest",300);
		return;
	}
	message("channel/snow",HIC"【"HIM"俠客行一百"HIC"】"HIW"七殺門首領天殺星：看來中原的高手都是膽小鬼，我回去捲土重來！\n"NOR,users());
	message("channel/snow",HIC"【"HIM"俠客行一百"HIC"】"HIW"七殺門首領天殺星仰天“哈哈”長笑幾聲。\n"NOR,users());
	message_vision("$N一個縱身，轉眼就消失在茫茫人海之中。\n",ob);
	destruct(ob);
}

void die()
{
	object me;
	object shu;
	me = query("pk_target");
	shu = present("zhan shu",me);
	message_vision("$N説道：“哎,看來我命該如此啊！”説完兩眼一閉倒地死了。\n", this_object());
  if (userp(me) &&  environment(me)==environment(this_object()) &&
   objectp(shu) &&  shu->is_zhanshu())
	{
  destruct(shu);
	me->add("combat_exp",25000);
	me->add("potential",2500);
	tell_object(me,HIW"你殺死七殺門首領天殺星有功，獎勵你 25K 經驗和 2500 點潛能！\n"NOR);
	message("channel/snow",HIM"【謠言】某人：天殺星被"+me->name()+HIM"殺死了。\n"NOR,users());
  }
	::die();
}

void if_die()
{
	if ( !query("pk_target")->is_ghost() )
	{
		remove_call_out("if_die");
		call_out("if_die",3);
		return;
	}
	message("channel/snow",HIC"【"HIM"俠客行一百"HIC"】"HIW"七殺門首領天殺星大笑道：中原的武功也不過如此嘛！老子天下第一！待我回去捲土重來！哈！哈！哈！\n"NOR,users());
	message_vision("$N一個縱身，轉眼就消失在茫茫人海之中。\n",this_object());
	destruct(this_object());
}

int accept_hit(object me)
{
	object who, ob;
  object shu=present("zhan shu",me);
	ob = this_object();
	who = query("pk_target");
//	if ( who==me ) return 1;
	if ( shu && shu->is_zhanshu()) 
	{
		if (me!=ob->query_temp("last_damage_from")) copyto(me);
		return 1;
	}
	message_vision(HIW "$N一見$n在此搗亂，跳出來大喝一聲道：臭賊！給我滾到一邊去，不要妨礙老子決鬥！\n"NOR,ob,me);
	message_vision("只見$N飛起一個三百六十度旋風腿將$n踢了出去。\n",ob,me);
	me->move("/d/city/wumiao");
	message_vision("只聽“乒”地一聲，$N被人一腳踢了過來，模樣狼狽萬狀。\n",me);
  me->unconcious();
  me->start_busy(5);
	return notify_fail("");
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}

void killing(object ob)
{
	if ( environment(this_object()) != environment(ob) ) return;
	if ( (environment(ob)->query("no_fight")) ) return;

	message_vision("$N對著$n喝道：「"+RANK_D->query_rude(ob)+"！今天不是你死就是我亡！」\n",this_object(),ob);

  copyto(ob);
  
	this_object()->kill_ob(ob);
	remove_call_out("if_die");
	call_out("if_die",3);
	return;
}
void copyto(object player)
{
	object me=this_object();
	float exper;
	int i,level;
	int neili;
	mapping skill_status;
	string *sname;
	
	if (me->query("combat_exp") < player->query("combat_exp"))
	    me->set("combat_exp",player->query("combat_exp"));
	exper = to_float(me->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333));
  skill_status = me->query_skills();
  sname  = keys(skill_status);
	for (i=0;i<sizeof(skill_status);i++)
	{
		me->set_skill(sname[i],level);
	}
	me->revive(1);
	me->set("qi",me->query("max_qi"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("jing",me->query("max_jing"));
	me->set("eff_jing",me->query("max_jing"));
	neili = 5000;
	if (player->query("neili") > neili ) neili = player->query("neili");
	if (player->query("max_neili") > neili ) neili = player->query("max_neili");
  me->set("max_neili",neili);
  me->set("neili",neili);
  me->set("jiali", neili/20);
}