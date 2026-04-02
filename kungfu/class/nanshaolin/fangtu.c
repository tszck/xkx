// Npc: /kungfu/class/nanshaolin/fangtu.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me_1(string name);
string ask_me_2(string name);

void create()
{
	set_name("方土", ({ "fang tu", "fang", "tu"}));
	set("long", "他是一位身穿黃布袈裟的青年僧人。臉上稚氣未脫，身手卻已相\n"
		"當矯捷，看來似乎學過一點武功。\n");
	set("nickname", "防具頭");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("whip", 50);
	set_skill("jiujie-whip", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "fengyun-hand");
	map_skill("whip", "jiujie-whip");
	map_skill("parry", "jiujie-whip");
	prepare_skill("cuff", "luohan-cuff");
	prepare_skill("hand", "fengyun-hand");

	set("inquiry", ([
		"護腕"   : (: ask_me_1, "huwan" :),
		"護腰"   : (: ask_me_1, "huyao" :),
		"沙袋"   : (: ask_me_1, "shadai" :),
		"護心"   : (: ask_me_1, "huxin" :),
		"護指"   : (: ask_me_1, "huzhi" :),
		"僧鞋"   : (: ask_me_1, "sengxie" :),
		"鐵背心" : (: ask_me_2, "beixin" :)
	]));
	set("huju_count", 50);
	set("beixin_count", 5);
	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"whip/whip")->wield();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if ( present(name, this_player()) )
		return RANK_D->query_respect(this_player()) +"你現在身上不是有這樣防具嗎，怎麼又來要了？真是貪得無饜！";
	if (query("huju_count") < 1)
		return "抱歉，你來得不是時候，防具已經發完了。";
	ob = new(ARMOR_DIR + name);
	ob->move(this_player());
	add("huju_count", -1);
	message_vision("方土給$N一件"+ob->query("name")+"。\n", this_player());
	return "拿去吧。不過要記住，防具只可防身練武，不可憑此妨害他人。";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if (query("beixin_count") < 1)
		return "抱歉，你來得不是時候，武器已經發完了。";
	ob = new(ARMOR_DIR + name);
	ob->move(this_player());
	add("beixin_count", -1);
	message_vision("方土給$N一件"+ob->query("name")+"。\n", this_player());
	return "拿去吧。不過要記住，鐵背心乃是防身寶物，不可憑此妨害他人。";
}
#include "/kungfu/class/nanshaolin/fang.h";
