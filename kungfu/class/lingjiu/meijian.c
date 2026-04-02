// /NPC meijian.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
	set_name("梅劍", ({ "mei jian", "mei"}));
	set("long",
		"這是個容貌姣好的女子，瓜子臉蛋，眼如點漆，清秀絕俗。
你總覺得在哪見過她。\n");
	set("title", "靈鷲宮第三代弟子");
	set("gender", "女性");
	set("class", "dancer");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 1500);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 50000);
	set("score", 10000);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("hand",70);
	set_skill("strike", 70);
	set_skill("sword",100);
	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",150);
	set_skill("yueying-wubu",120);
	set_skill("bahuang-gong", 70);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.san" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("逍遙派",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/food/jiudai");
	add_money("silver",15);
}

void init()
{
	object ob;
 
	::init();
 
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if ((string)ob->query("family/family_name") == "靈鷲宮"
	  && environment(ob)==environment()) 
	{
		message_vision("梅劍衝着$N點點頭，微微笑了笑。\n",ob);
		return;
	}
	if (!(string)ob->query("family/family_name"))
	{
		message_vision("梅劍衝着$N微笑說：你是來拜師的吧，拜我吧。\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender")=="女性")
	{
		message_vision("梅劍垂目沉思片刻, 說道：“好吧, 我就收下你了。”\n",ob);
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("梅劍瞪着$N看了半天,說道：“閣下是否該去做做手術?”\n",ob);
		return;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		ob->set("title","靈鷲宮第四代弟子");
	}
}