// hetieshou.c 何鐵手
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
int ask_me();
int ask_box();
string ask_ling();

void create()
{
	object ob;
	set_name("何鐵手", ({ "he tieshou", "he" }));
	set("nickname", HIG "五毒仙子" NOR);
	set("long",@LONG
你對面的是一個一身粉紅紗裙，笑靨如花的少女。她長得肌膚雪白，眉目如畫，
赤着一雙白嫩的秀足，手腳上都戴着閃閃的金鐲。誰能想到她就是五毒教的教
主何鐵手，武林人士提起她無不膽顫心驚。
LONG
	);
	set("title","五毒教教主");
	set("gender", "女性");
	set("class", "shaman");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 36);
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("box_count",1);
	set("ling_count",1);
	set("tieshao_count",1);

	set_skill("force", 200);
	set_skill("wudu-shengong", 200);
	set_skill("dodge", 200);
	set_skill("wudu-yanluobu", 300);
	set_skill("hand", 170);
	set_skill("qianzhu-wandushou", 250);
	set_skill("strike", 170);
	set_skill("wudu-zhang", 250);
	set_skill("parry", 190);
	set_skill("whip", 200);
	set_skill("wudu-whip", 300);
	set_skill("hook", 200);
	set_skill("wudu-goufa", 300);
	set_skill("sword", 200);
	set_skill("qingmang-sword", 300);
	set_skill("five-poison", 200);
	set_skill("literate", 100);
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("whip", "wudu-whip");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");

	set("no_get",1);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "unarmed.qzwd" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("五毒教", 11, "教主");

	setup();
	set("inquiry", ([
		"萬毒窟"    : (: ask_me :),
		"信物"      : (: ask_me :),
		"含沙射影"  : (: ask_box :),
		"五毒令"    : (: ask_ling :),
	]) );
  if (clonep())
  {
  	ob=new(WEAPON_DIR"treasure/jinfenggou");
  	if ( ob->violate_unique() )
  	 {
  	 	 destruct(ob);
  	 	 ob=new("/clone/weapon/hook");
  	 	}
  	 	ob->move(this_object());
  	 	ob->wield();
  }
	carry_object("/clone/armor/treasure/skirt")->wear();

	add_money("silver",50);
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

int ask_me()
{
	object ob;
	if ((string)this_player()->query("family/master_id")!="he tieshou")
	{
		command("say 萬毒窟乃本教聖地，除本教長老之外別人不得進入。");
		return 1;
	}
	if(query("tieshao_count")< 1 )
	{
		command("say 你來晚了，信物我已經給別人了。");
		return 1;
	}
	command("say 萬毒窟內兇險異常，千萬要小心啊。\n");
	command("say 這隻鐵哨是我的信物，你可以憑此自由進入洞中！");
	ob = new("/d/wudujiao/npc/obj/tieshao");
	ob->move(this_player());
	add("tieshao_count",-1);
	remove_call_out ("give_tieshao");
	call_out ("give_tieshao", 900); // 15 分鐘
	return 1;
}
int ask_box()
{
	object ob;
	if ((string)this_player()->query("family/master_id")!="he tieshou")
	{
		command("say 此乃本教重寶，輕易不會給人的。");
		return 1;
	}
	if(query("box_count")< 1 )
	{
		command("say 你來晚了，含沙射影我已經送給別人了。");
		return 1;
	}
	command("smile");
	command("say 怎麼？是要和人打架嗎？可別弱了我五毒教威風啊！");
	command("say 含沙射影你拿去吧，叫他們嚐嚐我們五毒教的厲害。");
	ob = new("/d/wudujiao/npc/obj/hanshasheying");
	ob->move(this_player());
	add("box_count",-1);
	ob->set("own_name",this_player()->query("id"));
	remove_call_out ("give_hssy");
	call_out ("give_hssy", 900); // 15 分鐘
	return 1;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "無性")
	{
		command("say 這位公公不要開玩笑了。");
		command("say 這位" + RANK_D->query_respect(ob)+"還是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > 1000)
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

	if ((int)ob->query_skill("five-poison", 1) < 120)
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

//	command("chat 嘿嘿嘿嘿！！！！！");
	command("chat 好吧，既然如此本姑娘就收下你這個徒弟。");
	command("chat 終有一天，要讓天下人都知道我們五毒教的厲害！！！");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"五毒教長老"NOR);
	return;
}
void give_hssy()
{
	set("box_count",1);
}
void give_tieshao()
{
	set("tieshao_count",1);
}
void give_wuduling()
{
	set("ling_count",1);
}
string ask_ling()
{
	mapping fam;
	object *allob,env,ob,me=this_player();
 
	int i, count, here = 0;

	if (query("ling_count") < 1)
		return "你來晚了，五毒令別的教衆正在用呢。\n";
	if (!(fam = me->query("family")) || fam["family_name"] != "五毒教")
		return RANK_D->query_respect(me) + "與本派素無來往，不知此話從何談起？";

	if (me->query("duchong_cun") == 1)
		return "你的毒蟲不是在毒叟那好好的麼？";

	env = environment(me);
	allob = all_inventory(env);
	count = 0;
	for(i=0; i<sizeof(allob); i++)
		if(allob[i] != me && allob[i]!=this_object() )
		{
			if(allob[i]->query("host_id") == me->query("id"))
			{
				here = 1;
			}
			count++;
		}
	if (here == 1)
		return "你的毒蟲不是帶在身邊了嗎！？";
	if (me->query("duchong_cun") == 0 && count >= 1)
		return "現在人多眼雜，你回頭再來吧！";

	if (!me->query("du/id"))
		return "你沒養毒蟲吧！";

	add("ling_count",-1);
	ob = new(__DIR__"obj/wudu-ling");
	ob->move(me);
	message_vision("$N獲得一面五毒令。\n",me);
	remove_call_out ("give_wuduling");
	call_out ("give_wuduling", 600); // 10 分鐘

	return "好吧，憑這面五毒令，你可去要回你的毒蟲。";

}
