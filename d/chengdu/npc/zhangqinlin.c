// zhangqinlin.c 張禽林 
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("張禽林", ({ "zhangqinlin", "zhang", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "由於生意不大好，所以他臉上也沒什麼笑容。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "阿林");
	set("vendor_goods", ({
		__DIR__"obj/zongzi",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

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


void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n只聽阿林大喝一聲：你這臭要飯的進來幹什麼？給我滾出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/chengdu/xiaojie1");
	message("vision", "只聽“乒”地一聲，" + ob->query("name") + "被人從糉子店裏一腳踢了出來，狼狽萬狀的逃開了。\n", environment(ob), ob);
}
