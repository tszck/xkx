// yin.c 殷梨亭
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("殷梨亭", ({ "yin liting","yin"}));
	set("nickname", "武當六俠");
	set("long","他就是張三豐的最軟弱的弟子、武當七俠之六的殷梨亭。\n身穿一件乾乾淨淨的青布長衫。\n他不過二十出頭年紀，精明能幹，嫉惡如仇，性如烈火，卻一直一副不愉快的表情。\n只見他滿臉風塵之色，兩鬢微見斑白，\n在武當七俠中排名第六，對劍法尤爲精通。\n");
	set("gender", "男性");
	set("age", 23);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 26);
	set("int", 39);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 60000);

	set_skill("force", 95);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 95);
	set_skill("tiyunzong", 130);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi-jian", 150);
	set_skill("taiji-jian", 150);
	set_skill("wudang-jian", 100);
	set_skill("wudang-quan", 100);
	set_skill("literate", 95);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
		"紀曉芙" : "可憐我那未過門的妻子，居然被楊逍那淫徒。。。",
		"楊逍"   : "總有一天我要手刃這魔教淫賊，以祭曉芙在天。。。",
		"神門十三劍" : "神門十三劍乃。。。唉，可憐曉芙居然被楊消那淫徒。。。",
	]));

	create_family("武當派", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("wudang/offerring") < 5) {
		command("say " + RANK_D->query_respect(ob) +
			"你對我武當派盡了多少心力，有幾分忠心呢？");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 40) {
		command("say 我武當派乃內家武功，最重視內功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否還應該在太極神功上多下點功夫？");
		return;
	}
	if ((int)ob->query("shen") < 80000) {
		command("say 我武當乃是堂堂名門正派，對弟子要求極嚴。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否還做得不夠？");
		return;
	}
        command("sigh");
        command("say 雖然"+RANK_D->query_respect(ob)+"也是我輩中人，但自曉芙去後，我已無心收徒；不過你我今日相見也是有緣，我就傳你一式“天地同壽”，也不枉你我相識一場。");
        ob->set("wudang/yinliting_teach", 1);
}
