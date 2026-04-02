// hehongyao.c
// 何紅藥
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("何紅藥", ({ "he hongyao", "he" }));
	set("nickname", HIG "疤面丐婆" NOR);
	set("long",@LONG
他就是五毒教的長老，教主的姑姑何紅藥。隨然是教主的長輩，但功夫卻是一塊跟
上代教主學的。據說她曾經被立爲教主繼承人，但後來犯下大錯，所以被罰到此處
看守聖地，以贖前罪。她穿着一身破舊的衣衫，滿臉疤痕，長得骨瘦如柴，雙目中
滿是怨毒之色。
LONG
	);
	set("title","五毒教長老");
	set("class", "beggar");
	set("gender", "女性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 10);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("wudu-shengong", 200);
	set_skill("dodge", 190);
	set_skill("wudu-yanluobu", 250);
	set_skill("hand", 160);
	set_skill("qianzhu-wandushou", 220);
	set_skill("strike", 160);
	set_skill("wudu-zhang", 220);
	set_skill("parry", 180);
	set_skill("hook", 200);
	set_skill("wudu-goufa", 300);
	set_skill("sword", 200);
	set_skill("qingmang-sword", 300);
	set_skill("five-poison", 160);
	set_skill("literate", 80);

	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("hook", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
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
	setup();

	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/jiandao");
		if ( ob->violate_unique())
       destruct(ob);
    else
      {
      	ob->move(this_object());
        ob->wield();
      }
		}
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object("/clone/medicine/poison/wuxing");

	add_money("silver",30);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "無性")
	{
		command("say 這位公公不要開玩笑了。");
		command("say 這位" + RANK_D->query_respect(ob) +"還是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > -10000)
	{
		command("say 做我五毒教弟子必須心狠手辣。");
		command("say 這位" + RANK_D->query_respect(ob) +"心慈手軟，可惜與我教沒有緣分啊！");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 這位" + RANK_D->query_respect(ob) +"不是本教弟子，還是請回吧！");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 100)
	{
		command("say 我五毒教弟子以毒殺人，修習毒技是首要的。");
		command("say 這位" + RANK_D->query_respect(ob) + "是否還應該多多鑽研本門的絕學？");
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

