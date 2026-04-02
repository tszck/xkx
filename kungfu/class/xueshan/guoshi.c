// /kungfu/class/xueshan/guoshi.c  貢唐倉國師

#include <ansi.h>
#include "xueshan.h";

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
	set_name("貢唐倉國師", ({ "gongtangcang guoshi", "guoshi" }));
	set("long",@LONG
貢唐倉國師是雪山寺中地位較高的喇嘛。
身穿一件青色袈裟，頭帶僧帽。
LONG
	);
	set("title", HIY "大喇嘛" NOR);
	set("nickname", HIG "國師" NOR);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 24);
	set("int", 28);
	set("con", 26);
	set("dex", 25);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 20);
	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("lamaism", 60);
	set_skill("literate", 50);
	set_skill("force", 100);
	set_skill("xiaowuxiang", 100);
	set_skill("dodge", 100);
	set_skill("shenkong-xing", 150);
	set_skill("parry", 70);
	set_skill("staff", 80);
	set_skill("xiangmo-chu", 120 );
	set_skill("sword",50);
	set_skill("mingwang-jian",70);
	set_skill("unarmed", 90);
	set_skill("yujiamu-quan", 120);


	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "xiangmo-chu");
	map_skill("staff", "xiangmo-chu");
	map_skill("sword", "mingwang-jian");
	set("env/wimpy", 60);
	create_family("雪山寺", 4, "大喇嘛");
	set("class", "lama");

	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
	]));

	setup();

	carry_object("/d/shaolin/obj/chanzhang")->wield();
	carry_object("/d/xueshan/obj/c-jiasha")->wear();
	carry_object("/d/xueshan/obj/sengmao")->wear();

	add_money("silver",100);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") != "男性") {
		command("say 修習密宗內功需要純陽之體。");
		command("say 這位" + RANK_D->query_respect(ob) +
			"還是請回吧！");
		return;
	}

	if ((string)ob->query("class") != "lama") {
		command("say 我西藏黃教門內的清規戒律甚多。");
		ob->set_temp("pending/join_bonze", 1);
		command("say 施主若真心皈依我佛，請跪下(kneel)受戒。\n");
		return;
	}

	if ((string)ob->query("family/family_name") != "雪山寺")	{
		command("say 這位" + RANK_D->query_respect(ob) +
			"既非本寺弟子，還是請回吧！");
		return;
	}

	if ((int)ob->query_skill("lamaism", 1) < 40) {
		command("say 入我雪山寺，修習密宗心法是首要的。");
		command("say 這位" + RANK_D->query_respect(ob) +
			"是否還應該多多鑽研本門的心法？");
		return;
	}

	command("say 好，就傳你一些武功吧！");
	command("recruit " + ob->query("id"));

}

void init()
{
	add_action("do_kneel", "kneel");
	add_action("do_say", "say");
}

int do_say(string arg)
{

	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="法輪常轉" )	
	{
		me->move("/d/xueshan/guangchang");
		return 1;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	ob->set("title",HIY "喇嘛" NOR);
 				  }
}
