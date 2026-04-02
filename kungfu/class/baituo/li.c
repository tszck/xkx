// li.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("李教頭", ({ "li"}) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "這是個和藹可親的教頭。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 400);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 250000);
	set("score", 20000);
	set("env/wimpy", 60);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("parry", 80);
	set_skill("cuff", 80);
	set_skill("staff", 80);
	set_skill("hamaquan", 120);
	set_skill("hamagong", 70);
	set_skill("strike",80);
	set_skill("chanchu-bufa", 130);
	set_skill("lingshe-zhangfa", 120);
	map_skill("force", "hamagong");
	map_skill("cuff", "hamaquan");
	map_skill("dodge", "chanchu-bufa");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("cuff", "hamaquan");
	prepare_skill("strike", "hamagong");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: perform_action, "strike.hama" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("白駝山派", 3, "弟子");

	set("chat_chance", 2);
	set("chat_msg", ({
		"李教頭說道：勤學苦練方可出神功。\n",
		"李教頭鼓勵小弟子們不畏艱苦，好好練功。\n",
		"李教頭拍拍學徒的頭說：好樣的！\n",
	}) );
	setup();
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
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "白駝山派")
	{
		message_vision("李教頭衝着$N點點頭，微微笑了笑。\n",ob);
		return;
	}
	if (!(string)ob->query("family/family_name"))
	{
		message_vision("李教頭衝着$N微笑說：你是來拜師的吧，拜我吧。\n",ob);
		return;
	}
	message_vision("李教頭對$N嚷道：小傢伙，你瞎逛什麼呢？\n",ob);
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我收下你。\n");
	command("recruit "+ob->query("id"));
	if((int)ob->query("combat_exp")<10000)
		command("say 你先到東邊練功室找陪練童子比劃幾招吧。\n");
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("family/family_name") == "白駝山派")
	{
		if((int)ob->query("combat_exp")<1000)
			return notify_fail("李教頭笑道：你的經驗太低了，還是先找陪練童子比劃幾招吧。！\n");
	}
	return 1;
}
