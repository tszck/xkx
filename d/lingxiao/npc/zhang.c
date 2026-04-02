// Npc: /d/lingxiao/npc/zhang.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
string ask_jiu();

void create()
{
	set_name("張萬風",({"zhang wanfeng","zhang"}));
	set("gender", "男性");
	set("age", 20);
	set("long", "他是凌霄城第六代弟子張萬風，正在這喝酒喝得高興。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("qi", 1200);
	set("max_qi", 1200);
	set("inquiry", ([
	    "jiu"      : (: ask_jiu :), 
	    "參陽玉酒" : (: ask_jiu :), 
	]) ); 
	set("jiu_count", 2);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 60);
	set_skill("snow-strike", 60);
	set_skill("snowstep", 60);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian");
	carry_object(CLOTH_DIR+"bai")->wear();
}

string ask_jiu()
{
	object ob;

	if (this_player()->query_skill("force", 1) < 50)
		return "閣下看來就不是個飲酒之人，這酒烈啊";
//	if (this_player()->query("family/family_name") != "凌霄城")
//		return RANK_D->query_respect(this_player()) +"閣下非我凌霄弟子，我爲什麼要給你參陽玉酒？";
	if ( present("shenyang yujiu", this_player()) )
		return RANK_D->query_respect(this_player()) +"你身上就有一壺，還想要，別那麼貪心！"; 
	if (query("jiu_count") < 1)
		return "哎呀呀！最近好酒的人還真不少！對不起，參陽玉酒已經發完了。";
	if (random(5) != 0)
	{
		add("jiu_count", -1);
		command("wield sword");
		command("unwield sword");
		return "昨天師父還在問，最近怎麼窖裏的酒少了。你少來煩我。";
	}
	ob = new(NOSTRUM_DIR"shenyangjiu");
	ob->move(this_player());
	add("jiu_count", -1);
	message_vision("$N接過一壺參陽玉酒。\n",this_player());
	return "拿去吧，不要當酒喝呀。";
}

