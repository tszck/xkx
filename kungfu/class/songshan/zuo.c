// zuo.c

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>

string ask_book();
string ask_book1();
void create()
{
	set_name("左冷禪", ({ "zuo lengchan", "zuo" }) );
	set("title", HIR"五嶽劍派盟主"HIY"嵩山派第十三掌門"NOR);
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 3000000);
	set("shen", -200000);
	set("book_count", 1);
	set("book_count1", 1);

	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("songshan-sword", 300);
	set_skill("songyang-strike", 300);
	set_skill("poyun-hand", 300);
	set_skill("hanbing-zhenqi", 200);
	set_skill("fuguanglueying", 300);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("inquiry",([
		"祕籍"	     : (: ask_book :),
		"掌譜"	     : (: ask_book :),
		"大嵩陽掌譜" : (: ask_book :),
		"劍譜"	     : (: ask_book1 :),
		"嵩山劍譜"   : (: ask_book1 :),
	]));

	create_family("嵩山派", 13, "掌門");
	setup();

	carry_object(WEAPON_DIR+"kuojian")->wield();
	carry_object(__DIR__"obj/yellow-cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	command("say 我派為五嶽盟主！入我門來，定須光大我嵩山一派。");
	command("recruit " + ob->query("id"));
}

string ask_book()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="嵩山派")
		return RANK_D->query_respect(this_player()) +
		"與本派毫無瓜葛，我派的武功典籍可不能交給你。";
	if (query("book_count") < 1) return "你來晚了，本派的祕籍不在此處。";
	add("book_count", -1);
	ob = new("/clone/book/songyang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到大嵩陽掌譜啦。\n");
	return "好吧，這本「大嵩陽掌譜」你拿回去好好鑽研。";
}

string ask_book1()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="嵩山派")
		return RANK_D->query_respect(this_player()) +
		"與本派毫無瓜葛，我派的武功典籍可不能交給你。";
	if (query("book_count1") < 1) return "你來晚了，本派的祕籍不在此處。";
	add("book_count1", -1);
	ob = new("/clone/book/sword_book4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到嵩山劍譜啦。\n");
	return "好吧，這本「嵩山劍譜」你拿回去好好鑽研。";
}
