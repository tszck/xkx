// Last Modified by winder on Sep. 12 2001
// yu-yutong.c 餘魚同

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("餘魚同", ({ "yu yutong", "yu" }));
	set("nickname", YEL"金笛秀才"NOR);
	set("title", HIR"紅花會"HIG"十四當家"NOR);
	set("long","他是紅花會的十四當家，\n身穿一件極為合體的白色長衫，\n他年紀好像在二十上下，身穿白色長衫，長身玉立，眉清目秀，風流英俊的書生。\n他是江南望族子弟，中過秀才。\n父親因和一家豪門爭一塊墳地，官司打得傾家蕩產，又被豪門藉故陷害，瘐死獄中。\n餘魚同一氣出走，得遇機緣，拜馬真為師，棄文習武，刺死士豪後，亡命江湖。\n他為人機警靈巧，多識各地鄉談，在會中任聯絡四方、刺探訊息之職。\n");
	set("gender", "男性");
	set("class", "swordman");
	set("age", 21);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 400000);
	set("score", 100000);

	set_skill("force", 80);
	set_skill("honghua-shengong", 80);
	set_skill("dodge", 80);
	set_skill("youlong-shenfa", 120);
	set_skill("hand", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("benlei-shou", 120);
	set_skill("zhuihun-jian", 120);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("hand", "benlei-shou");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("紅花會", 2, "弟子");

	setup();
	carry_object("/kungfu/class/baituo/obj/baipao")->wear();
	carry_object(__DIR__"obj/yaodai")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="yu yutong")
	{
		command( "chat "+ob->query("name")+"！你這等邪惡奸詐之徒，我豈能仍是你的師父！\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","紅花會" + RED + "棄徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0)
	{
		command("say 我紅花會收徒極嚴。");
		command("say 這位" + RANK_D->query_respect(ob) + "平時還要多做一些行俠仗義之事！");
		return;
	}
	command("say 好，你這個年青人還不錯，我收下你了！");
	command("recruit " + ob->query("id"));
}

