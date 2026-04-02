// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/dabing.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me_1(object);

void create()
{
	set_name("大病大師", ({ "dabing dashi", "dabing", "dashi"}));
	set("long", "他是一位身材矮小的老年僧人，面上皺紋堆壘。\n"
		"慈眉善目，露出悲天憫人之像。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",200);
	set("combat_exp", 1000000);
	set("score", 5000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("zhanzhuang-gong", 150);
	set_skill("dodge", 150);
	set_skill("yiwei-dujiang", 220);
// basic skill begin
	set_skill("shaolin-cuff", 220);
	set_skill("luohan-cuff", 220);
	set_skill("weituo-strike", 220);
	set_skill("sanhua-strike", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("nianhua-finger", 220);
	set_skill("boruo-strike", 220);
// basic skill end
// 掌和刀
	set_skill("strike", 150);
	set_skill("blade", 150);
	set_skill("cibei-blade", 220);
	set_skill("xiuluo-blade", 220);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("strike", "boruo-strike");
	map_skill("blade", "xiuluo-blade");
	map_skill("parry", "xiuluo-blade");

	prepare_skill("strike", "boruo-strike");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "roar" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"鋼杵" : (: ask_me_1, "gangchu" :),
		"柴刀" : (: ask_me_1, "chaidao" :),
//		"撓鉤" : (: ask_me_1, "naogou" :),
//		"套索" : (: ask_me_1, "taosuo" :),
	]));
	set("weapon_count", 10);
//	set("tools_count", 5);

	create_family("南少林派", 19, "心禪堂首座");
	setup();
	carry_object(WEAPON_DIR+"blade/jiedao")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if ( present(name, this_player()))
		return RANK_D->query_respect(this_player()) +"你現在身上不是有這樣東西嗎，怎麼又來要了？ 真是貪得無饜！";
	if (!(this_player()->query("pass_xin")))
		return "你是偷偷進來的吧，請出去吧！\n";
	if (query("weapon_count") < 1)
		return "抱歉，你來得不是時候，東西已經發完了。";
	ob = new("/d/nanshaolin/obj/" + name);
	ob->move(this_player());
	add("weapon_count", -1);
	message_vision("大病給$N一件"+ob->query("name")+"。\n",this_player());
	return "拿去吧。用此物爲寺中服務。\n";
}

void attempt_apprentice(object ob)
{
	object me=this_object();
	mapping ob_fam, my_fam;
	string name, new_name;
	my_fam =me->query("family");
	name = ob->query("name");

	if(!(ob_fam=ob->query("family")) || ob_fam["family_name"]!="南少林派")
	{
		command("say "+RANK_D->query_respect(ob)+"與本派素無來往，不知此話從何談起？");
		return;
	}
	if( !(ob->query("pass_xin")) )
	{
		command("say"+RANK_D->query_respect(ob) +"是怎麼進來的？");
		return;
	}
	if( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"，貧僧哪裏敢當！");
		return;
	}
	if( ob->query_skill("force", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"，你的基本內功還需要磨練。貧僧到時再收你爲徒。");
		return;
	}
	if( ob_fam["generation"]==(my_fam["generation"]+1) && name[0..0]=="元")
	{
		command("say "+ob_fam["master_name"]+"的徒弟怎麼跑到我這兒來了，哈哈哈！");
		command("recruit "+ob->query("id"));
	}
	if( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		name = ob->query("name");
		new_name = "元" + name[1..1];
		command("say 老衲垂死之年，又得一可塑之才，真是可喜可賀 !");
		ob->set("name", new_name);
 		ob->set("title", "心禪堂職事僧");
		command("say 今後你的法名叫做"+new_name+"。\n");
		command("say 從今以後你就是心禪堂職事高僧了，望你好好深造！\n");
		command("recruit " + ob->query("id"));
	}
	else
		command("say "+RANK_D->query_respect(ob)+"，你是從哪蹦出來的，你不能越級拜師。");
	return;
}
