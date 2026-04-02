// mapo.c
// Last Modifyed by Winder on Dec. 24 2001

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("陳麻婆", ({ "chen mapo", "chen" }));
	set("title", "麻婆豆腐創始人");
	set("nickname",HIW "豆腐西施" NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 25);
	set("long",
		"陳麻婆可是成都城出名的人物，雖然年過三十，依然風韻猶存。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
		"麻婆豆腐" : "這是我們成都的特產，安逸得很哦。\n",
	]));
	set("vendor_goods", ({
		__DIR__"obj/doufu",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
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
		say("陳麻婆笑咪咪地說道：這位" + RANK_D->query_respect(ob) +
			"，快請進。\n");
		break;
	case 1 :
		say("陳麻婆說道：喲！這位" + RANK_D->query_respect(ob) + 
			"您來了啊！本店的麻婆豆腐硬是安逸得很！\n");
		break;
	}
}


