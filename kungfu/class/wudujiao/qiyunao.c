// qiyunao.c
// 齊雲敖
// by star
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("齊雲敖", ({ "qi yunao", "qi" }));
	set("nickname", HIG "錦衣毒丐" NOR);
	set("long",@LONG
他就是五毒教的長老，人稱錦衣毒丐的齊雲敖。乃是教主的同門師兄，在教中
一向飛揚跋扈，大權獨攬。他長的身材魁梧，面目猙獰，身穿一件五彩錦衣，太陽
穴高高墳起。
LONG
	);
	set("title","五毒教長老");
	set("gender", "男性");
	set("class", "shaman");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 12);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 170);
	set_skill("wudu-shengong", 170);
	set_skill("dodge", 160);
	set_skill("wudu-yanluobu", 220);
	set_skill("hand", 200);
	set_skill("qianzhu-wandushou", 300);
	set_skill("strike", 200);
	set_skill("wudu-zhang", 300);
	set_skill("parry", 200);
	set_skill("sword", 170);
	set_skill("hook", 170);
	set_skill("wudu-goufa", 250);
	set_skill("qingmang-sword", 250);
	set_skill("five-poison", 150);
	set_skill("literate", 80);
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "hand.qzwd" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("五毒教", 11, "長老");
	set("jinshe_count", 1);
	set("chat_chance",5);
	set("chat_msg",({
		"齊雲敖怒道：這賤婢這樣下去，本教三祖七子辛苦創下的基業都要毀在她手裏了。\n",
		"齊雲敖自言自語道：我如能找到天下最厲害的毒聖，這教主之位就是我的了。\n",
	}));
	setup();

	carry_object("/d/wudujiao/npc/obj/jinshechui")->wield();
	carry_object("/d/wudujiao/npc/obj/jinyi")->wear();
	carry_object("/clone/book/poisonbook2");

	add_money("silver",10);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "無性")
	{
		command("say 這位公公不要開玩笑了。");
		command("say 這位" + RANK_D->query_respect(ob) + "還是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > -10000)
	{
		command("say 做我五毒教弟子必須心狠手辣。");
		command("say 這位" + RANK_D->query_respect(ob) + "心慈手軟，可惜與我教沒有緣分啊！");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 這位" + RANK_D->query_respect(ob) + "不是本教弟子，還是請回吧！");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 100)
	{
		command("say 我五毒教弟子以毒殺人，修習毒技是首要的。");
		command("say 這位" + RANK_D->query_respect(ob) +
			"是否還應該多多鑽研本門的絕學？");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 100)
	{
		command("say 你的五毒神功還學的不夠啊。");
		return;
	}

	command("chat 嘿嘿嘿嘿！！！！！");
	command("chat 該當我五毒教發揚光大，稱霸武林指日可待了。");
	command("chat 嘿嘿嘿嘿！！！！！");
	command("recruit " + ob->query("id"));

	ob->set("title",HIY"五毒教護法"NOR);
	return;
}
int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你沒有這件東西。\n");

	if ( (string)ob->query("name") != HIC "龍涎香" NOR )
		return notify_fail("齊雲敖搖頭道：這些破爛東西給我有什麼用啊？\n");
	message_vision("齊雲敖見是龍涎香，大喜道：這、這就是龍涎香嗎？真是太好了！\n",who);
//	destruct(ob);
	obn=new("/d/wudujiao/npc/obj/jinsheduye");
	obn->move(who);
	message_vision("\n齊雲敖說道：本長老不能白收你的東西，這是一瓶金蛇毒液，送給你吧！\n",who);
	return 1;
}

