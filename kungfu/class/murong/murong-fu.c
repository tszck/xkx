// murong-fu.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("慕容復", ({ "murong fu", "murong","fu" }));
	set("nickname", HIG"南慕容"NOR);
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("san_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("strike", 200);
	set_skill("finger", 200);
	set_skill("murong-sword", 300);
	set_skill("murong-blade", 300);
	set_skill("canhe-finger", 300);
	set_skill("xingyi-strike", 300);
	set_skill("shenyuan-gong", 200);
	set_skill("yanling-shenfa", 300);
	set_skill("douzhuan-xingyi", 150);
	map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("parry", "douzhuan-xingyi");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("inquiry",([
		"王語嫣"    : "語嫣是我表妹，我一直把她當小妹妹看待。\n",
		"南慕容"    : "“南慕容北喬峯”，那是江湖上的朋友抬愛了！\n",
		"慕容復"    : "那是賤名。請教尊駕是？\n",
		"鄧百川"    : "你問鄧大哥啊？他在他青風莊上呢。\n",
		"公冶乾"    : "公冶二哥把信鴿傳書一編碼，就沒幾個人讀得懂了。\n",
		"包不同"    : "包三哥最愛擡槓了，你見了他還是閉嘴的好。\n",
		"風波惡"    : "風四哥最是豪爽了，他從不與人計較什麼。\n",
		"風波惡"    : "風四哥最是豪爽了，他從不與人計較什麼。\n",
		"玉露清新散": (: ask_me :),
	]) );
	set("no_get",1);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: perform_action, "parry.xingyi" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("姑蘇慕容",33, "弟子");
 	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say 這位" + RANK_D->query_respect(ob) +
			"，我慕容家復國乃至爲要事，你心志不堅，無緣我門。");
		return;
	}
	if ((int)ob->query_skill("shenyuan-gong", 1) < 100)
	{
		command("say 姑蘇慕容家武功，以內功爲根基。");
		command("say "+RANK_D->query_respect(ob)+"還應該多加努力！");
		return;
	}
	command("say 好吧我就收你爲徒吧。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑蘇慕容")
		return RANK_D->query_respect(this_player()) + 
		"與本派素無來往，不知此話從何談起？";
	if (query("san_count") < 1)
		return "你來晚了，本派的玉露清新散不在此處。";
	add("san_count", -1);
	ob = new("/clone/medicine/nostrum/yulusan");
	ob->move(this_player());
	return "好吧，這玉露清新散你拿去吧。";
}
