// miejue.c 滅絕師太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
	set_name("滅絕師太", ({ "miejue shitai","miejue","shitai"}));
	set("long", "她俗家姓方，是峨嵋派的第三代弟子，現任峨嵋派掌門人。\n");
	set("gender", "女性");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 100000);
	set("class", "bonze");
	set("no_get",1);
	set("inquiry",([
		"剃度" : "貧尼只知除妖殺魔，不剃度弟子。",
		"出家" : "貧尼只知除妖殺魔，不剃度弟子。",
		"還俗" : (: ask_for_quit :),
	]));

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",130);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 3000000);
	set("score", 1000);
	set_skill("persuading", 150);
	set_skill("throwing", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("literate", 100);
	set_skill("mahayana", 200);
	set_skill("buddhism", 200);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("huifeng-jian", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang", 200);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("blade","yanxing-dao");
	map_skill("parry","huifeng-jian");
//	map_skill("magic","bashi-shentong");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
//		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
	create_family("峨嵋派", 3, "掌門");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}

void init()
{
	object ob;
	mapping myfam;

	::init();
	if (interactive(ob=this_player()) && ob->query("family"))
	{
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "峨嵋派")&&(!ob->query_skill("linji-zhuang",1))&&(ob->query("combat_exp")>500000))
       		{
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + ob->query("id"));
        	}
	}
    	add_action("do_qiecuo","qiecuo");
//    	add_action("do_kneel", "kneel");

}

void attempt_apprentice(object ob)
{
	mapping ob_fam;
 

	string name, new_name;
	name = ob->query("name");

	if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say " + RANK_D->query_respect(ob) + "與本派素無來往，不知此話從何談起？");
		return;
	}
	switch (random(2))
	{
		case 1: break;
		default:
			if ((string)ob->query("class")!="bonze" )
			{
				command ("say 阿彌陀佛！貧尼不收俗家弟子。");
				return;
			}
			else
			{
				command ("say 阿彌陀佛！貧尼不收弟子。");
				return;
			}
	}
	if ((int)ob->query_skill("mahayana",1)<90 ||
		(int)ob->query_skill("linji-zhuang",1)<90)
	{
		command("say 你本門的功夫修為還太低。");
		return;
	}
	if ((int)ob->query("shen") < 50000)
	{
		command("say "+RANK_D->query_respect(ob)+"你行俠仗義之事還做的不夠。");
		return;
	}
	if ((string)ob->query("class")=="bonze" )
	{
		name = ob->query("name");
		new_name = "靜" + name[1..1];
		ob->set("name", new_name);
		command("say 從今以後你的法名叫做" + new_name + "，恭喜你成為峨嵋第四代弟子!");
	}

	command("say 阿彌陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，濟度眾生。");
	command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
	object me = this_player();
	mapping myfam;

	myfam = (mapping)me->query("family");
	if (!myfam || (myfam["family_name"] != "峨嵋派"))
		return ("你和峨嵋沒有淵源，貧尼不敢給你還俗。\n");
	if( (string)me->query("class")!="bonze" )
		return "阿彌陀佛！出家人不打誑語。你已經是俗家人了。\n";
	if (!me->query_temp("pending/quit_bonze") && random(5)!=1)
		{
			command("heng");
   	 return "你好好的給我安心修煉，以後降妖除魔，別天天滿腦子不正經。";
		}
		me->set_temp("pending/quit_bonze", 1);
		command ("say 阿彌陀佛！善哉！善哉！你一心要還俗，我也不挽留。\n");
		command ("say 我將廢去你部分武功。請跪下(kneel)聽宣。\n");
		add_action("do_kneel","kneel");
		return "如果不願還俗的，就安心在此修煉吧。";
}

int do_kneel(string arg)
{
		object me=this_player();
  
		command("say 既然你已無心在我峨嵋修煉，貧尼就成全你。");
		command("say 從今往後，峨嵋再也沒有"+me->query("name")+"這號人物。");
		me->delete_temp("pending/quit_bonze");
		me->delete_skill("linji-zhuang");
		me->delete_skill("mahayana");
		me->delete("class");
		me->set("detach/emei",1);
		command("expell " + me->query("id"));
//	me->delete("betrayer");
		return 1;
}