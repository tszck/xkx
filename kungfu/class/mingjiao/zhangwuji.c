// /kungfu/class/mingjiao/zhangwuji.c
// Last Modified by winder on Oct. 30 2001

#include <ansi.h>
inherit F_MASTER;
inherit F_MANAGER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
void create()
{
	object ob;
	seteuid(getuid());
	set_name("張無忌", ({ "zhang wuji", "zhang", "wuji" }));
	set("long", "明教教主張無忌，統領天下十萬教眾，豪氣幹雲，叱吒千秋，\n"
		+"「九陽神功」、「乾坤大挪移」獨步天下，是江湖中不世出的\n"
		+"少年英雄。\n");
	set("gender", "男性");
	set("age", 20);
	set("shen_type",1);
	set("attitude", "friendly");
	set("class", "fighter");

	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3050);
	set("max_qi", 3050);
	set("jing", 3050);
	set("max_jing", 3050);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 150);

	set("combat_exp", 3000000);
	set("score", 455000);
	
	set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("claw", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword",200);
	set_skill("blade", 200);
	set_skill("jiuyang-shengong", 200);
	set_skill("qiankun-danuoyi", 250);
	set_skill("sougu", 200);
	set_skill("hanbing-mianzhang", 200);
	set_skill("qishang-quan", 200);
	set_skill("lieyan-dao", 300);
	set_skill("liehuo-jian", 300);
	set_skill("shenghuo-ling", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("sword","shenghuo-ling");
	map_skill("parry","shenghuo-ling");
	map_skill("claw", "sougu");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("cuff", "qishang-quan");
	map_skill("blade", "lieyan-dao");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	prepare_skill("cuff", "qishang-quan");

	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIM"教主"NOR);
	create_family("明教", 34, "弟子");

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.tougu" :),
		(: perform_action, "sword.yinfeng" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	set("chat_chance",2);
	set("chat_msg",({
"張無忌憤然説道：“大丈夫當以國為家，捐軀沙場，抗元大業未成，同輩仍需努力！”\n",
"張無忌嘆道：“人生失一知己，生亦何歡，死亦何憂，敏兒，你在哪裏？”\n",
"張無忌道：“我教兄弟聽了：生於亂世，當克己為公，行俠仗義，蕩寇驅魔！”\n",
	}));

	set("inquiry",([
		"金毛獅王":"那是我義父謝大俠的職司。\n",
		"謝遜"  :"他就是我義父的大號。\n",
		"張翠山":"你想找我父親有事麼？\n",
		"殷素素":"我媽是明尊座下紫微堂主。\n",
		"張三豐":"我太師父近來可好？\n",
		"趙敏"  :"人生失一知己，生亦何歡，死亦何憂，敏兒，你在哪裏？\n",
		"小昭"  :"小昭我可一直念着她的好處。\n",
		"周芷若":"找她就去峨嵋山，別來煩我。\n",
	]));
	setup();
	if (clonep())
	{
    ob=new(WEAPON_DIR"treasure/yitian-jian");
    if (ob->violate_unique())
      destruct(ob);
    else
      ob->move(this_object());
	}
	carry_object("/clone/book/shenghuo-ling")->wield();
	carry_object("/d/mingjiao/obj/baipao")->wear();
	add_money("silver",70);
}

void init()
{
	object ob;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
      
        add_action("do_qiecuo","qiecuo");
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	if((int)ob->query("shen")<-50000)
	{
		command("wield shenghuo ling");
		command("hit"+(string)ob->query("id"));
		command("unwield shenghuo ling");
	}
	else if((int)ob->query("shen")<-5000)
	{
		command("say 魔從心起，於武學不利，其道必誅，勸君放下屠刀，立地成佛。");
	}
	else if((int)ob->query("shen")<-100)
	{
		command("say 這位朋友，人行江湖，言行當正，切務走進邪魔歪道。");
	}
	else if((int)ob->query("shen")>=0)
	{
		command("say 光明正道任人走，勸君多加保重。");
	}
	else if((int)ob->query("shen")>10000)
	{
		command("say 大俠在上，受無忌一禮，大俠它日必為武林翹楚。");
	}
	return;
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say 你的悟性太低了，不適合學習我的功夫。");
		return 0;
	}
	if((string)ob->query("gender")=="無性")
	{
		command("say 你陽氣不足，習我功夫恐將走火如魔。");
		return 0;
	}
	if((int)ob->query("shen") <= 15000)
	{
		command("say 你應當多作些行俠仗義的事，以修身心。");
		return 0;
	}
	command("say 好，我就收下你這位好徒弟！");
	command("recruit " + ob->query("id"));
	return;
}

int accept_fight(object ob)
{
	if(((int)ob->query("combat_exp")<30000)&&((int)ob->query("shen")>0))
	{
		message_vision("武林中人最忌爭強鬥狠，你不是我的對手，回去吧。\n",ob);
		return 0;
	}
	message_vision("張無忌一拱手説道：這位"+RANK_D->query_respect(ob)+
	"，在下領教了。\n", ob);
	return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
			command("say 你的職司就是本教的光明使者。");
			ob->set("title", HIR"明教使者"NOR);
 				  }
}
