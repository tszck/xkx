// Room: /d/5lt/npc/xiaoer.c 酒店小二

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"這位店小二正笑眯眯地忙著，還不時拿起掛在脖子上的抹布擦臉。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		FOOD_DIR"jitui",
		LIQUID_DIR"jiudai",
		FOOD_DIR"baozi",
		__DIR__"obj/wuliangye",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{	
	object ob = this_player();
	mapping myfam; 

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		if ( (myfam = ob->query("family")) &&
			myfam["family_name"] == "丐幫" &&
			ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑眯眯地説道：這位" + RANK_D->query_respect(ob) + "，歡迎光臨悅華酒樓。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，説道：這位" + RANK_D->query_respect(ob) + "，請進請進。\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一聲：你這臭要飯的進來幹什麼？ 給我滾出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/chengdu/chunxilu1");
	message("vision","只聽“乒”地一聲，" +  ob->query("name") + "被人從悅華酒樓裏一腳踢了出來，狼狽萬狀地逃開了。\n", environment(ob), ob);
}
