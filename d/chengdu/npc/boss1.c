// Room: /d/chengdu/npc/boss1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("茶博士", ({ "cha boshi", "boshi"}));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 36);
	set("long",
		"他成天帶着笑容，可是心頭卻靈醒得很。\n"+
		"作爲茶館的老闆，成天和一幫沒事幹的無聊傢伙混在一起。\n"+
		"消息很是靈通。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		FOOD_DIR"peanut",
		FOOD_DIR"tofu",
		__DIR__"obj/longhucui",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("茶博士笑眯眯地說道：這位" + RANK_D->query_respect(ob) + "，快請進來喝杯熱茶。\n");
		break;
	case 1 :
		say("茶博士說道：喲！這位" + RANK_D->query_respect(ob) + "您來了啊！本店有剛炸好的五香花生出售。\n");
		break;
	}
}

