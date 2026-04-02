// oldman.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
	set_name("白髯老者", ({ "old man", "oldman"}) );
	set("gender", "男性" );
	set("age", 64);
	set("long", "一個鬚髮皆白的老者，精神矍鑠，滿面紅光。\n");
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set("title", "毒叟");
	set_skill("dodge", 120);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("force",120);
	set_skill("hammer", 120);
	set_skill("five-poison", 120);
	set_skill("hook",120);
	set_skill("literate", 50);
	set_skill("wudu-yanluobu", 120);
	set_skill("qianzhu-wandushou", 120);
	set_skill("wudu-shengong", 120);

	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("unarmed", "qianzhu-wandushou");
	map_skill("parry", "qianzhu-wandushou");
	set("vendor_goods", ({
		__DIR__"obj/jiedudan",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",30);
	set("inquiry", ([
		"寄存": (: ask_me :),
		"毒蟲": (: ask_me :),
		"照看": (: ask_me :),
	]) );
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
	switch( random(3) )
	{
		case 0:
			say("白髯老者掀髯笑道：這位" + RANK_D->query_respect(ob) + "，是來領你養的毒蟲的嗎？\n");
			break;
		case 1:
			say("白髯老者得意的道：老朽沒有別的嗜好，就是從小喜歡擺弄毒蟲，\n這位" + RANK_D->query_respect(ob) + "要是有事外出，身邊的毒蟲不妨交我照看。\n");
			break;
		case 2:
			say( "白髯老者嘿嘿奸笑道：這位" + RANK_D->query_respect(ob) +"不如將毒蟲寄存在老朽這裏吧，這裏暫時不收錢的。\n");
			break;
	}
}
int ask_me()
{
	object ob,me;
	me = this_player();
	if ((string)me->query("family/family_name") != "五毒教")
	{
		command("say 這位"+ RANK_D->query_respect(me)+ "不是本教弟子，怎麼跑到這裏來了？\n");
		return 1;
	}
	command("say 老朽對養蟲之道多有研究，把你的毒蟲寄存(cun)在我這吧。\n每次只收黃金一兩，領回(qu)時一次付清，不過是蟲子的飯錢而已。");
	return 1;
}

