// Npc: /d/lingxiao/npc/xuanyuan.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("軒轅蒼翼", ({ "xuanyuan cangyi", "xuanyuan" }));
	set("title", "刀劍鋪老闆");
	set("shen_type", 1);
	set("gender", "男性" );
	set("age", 33);
	set("long", "據說軒轅蒼翼是歐冶子的後代，爲了避免被權貴強迫鑄劍，\n"
		"才隱姓埋名在此開店，聽說幹將莫邪就在他手上。\n");
	set("combat_exp", 400000);
	set("inquiry", ([ 
		"幹將莫邪" : "“想要幹將莫邪，你可得先幫我個忙。先去幫我拿到雪山的冰魄玉精吧。”\n", 
		"幹將" : "“幹將乃先祖所鑄的邪劍，殺人太多，冤魂縈繞 。”\n", 
		"莫邪" : "“莫邪乃先祖所鑄的邪劍，殺人太多，冤魂縈繞 。”\n", 
	]));
	set("attitude", "friendly");
	set("vendor_goods",({
		WEAPON_DIR+"changjian",
		WEAPON_DIR+"gangdao",
		WEAPON_DIR+"hammer",
		WEAPON_DIR+"dagger",
		WEAPON_DIR+"qimeigun",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int accept_object(object who, object obj, object ob1, object ob2)
{
	if ((string)obj->query("id") != "bingpo yujing")
	{
		command("say 這位"+(string)who->query("name") +"我找你要過這玩意嗎？");
		return 0;
	}
	command("say 哈哈！我總算找到冰魄玉精了");
	ob1=new(WEAPON_DIR"treasure/ganjiang-jian");
	ob2=new(WEAPON_DIR"treasure/moye-jian");
	ob1->move(who);
	ob2->move(who);
	command("say 這位"+RANK_D->query_respect(who)+ "幫我找到了冰魄玉精，我也說話算數，這兩把劍你就拿去吧。\n");
	message_vision("軒轅蒼翼揭開一個長條盒子，嗖的一聲抽出兩把劍，遞給$N。\n",who);
	destruct(obj);
	return 0;
}

