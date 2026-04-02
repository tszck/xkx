// daoren.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
inherit F_MASTER;
int ask_me();

void create()
{
	set_name("遊方道人", ({ "dao ren", "dao", "daoren" }) );
	set("gender", "男性" );
	set("age", 34);
	set("class", "taoist");
	set("long",
		"一個白淨矮胖的道士，見誰都笑眯眯的，正悠閒的品着一杯香茶。\n");
	set("max_qi", 2000);
	set("per", 18);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("rank_info/respect", "笑面郎中");
	set_skill("dodge", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("force",80);
	set_skill("hammer", 80);
	set_skill("five-poison", 80);
	set_skill("sword",80);
	set_skill("literate", 50);
	set_skill("wudu-yanluobu", 70);
	set_skill("qianzhu-wandushou", 75);
	set_skill("wudu-shengong", 70);

	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("unarmed", "qianzhu-wandushou");
	map_skill("parry", "qianzhu-wandushou");
	set("env/wimpy", 60);
	set("inquiry", ([
	    "五毒教": (: ask_me :),
	]) );
	set("vendor_goods", ({
	       "/d/wudujiao/npc/obj/jiedudan",
	}));
	create_family("五毒教", 13, "護法弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",30);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "遊方道人嘿嘿一陣奸笑道：這位" + RANK_D->query_respect(ob) + "，也是來住店的嗎？\n");
			break;
		case 1:
			say( "遊方道人點了點手道：這位" + RANK_D->query_respect(ob) + "請過這裏坐，這是要去那啊？\n");
			break;
		case 2:
			say( "遊方道人面現驚訝之色道：這位" + RANK_D->query_respect(ob) + "眉現黑氣，近日會有大難。\n貧道有一些隨身丹丸可以賣給你，或許可救你一命。\n");
			break;
	}
}
void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "無性") {
		command("say 這位公公不要開玩笑了。");
		command("say 這位" + RANK_D->query_respect(ob) +
			"還是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > 1000) {
		command("say 做我五毒教弟子必須心狠手辣。");
		command("say 我教弟子貴在隨心所欲，不收偽君子");
		return;
	}

	command("recruit " + ob->query("id"));
	return;
}
int ask_me()
{
	object ob,me;
	me = this_player();
	if ((string)me->query("family/family_name") != "五毒教")
	      return notify_fail("對不起，無可奉告！\n");
	command("say 這位"+ RANK_D->query_respect(me)
	       + "來的正好，這裏正有馬車要回山辦事，就讓他們送你一程吧。\n");
	 message_vision(HIC"遊方道人一招手，一輛馬車駛過來停在門前。\n$N急忙鑽進車中，只聽一陣清脆的鞭響，馬車絕塵而去。\n\n"NOR,me);
	ob = load_object("/d/wudujiao/damen");
	ob = find_object("/d/wudujiao/damen");
	message("vision", "遠處一輛馬車急駛而來，車門一開"+me->query("name")+"從裏面鑽了出來。\n", ob);
	 tell_object(me, "只聽車把勢説道：這位"+ RANK_D->query_respect(me) + "已經到了，請下車吧。\n"NOR );
	me->move("/d/wudujiao/damen");
	return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	ob->set("title",HIY"五毒教徒"NOR);
 				  }
}
