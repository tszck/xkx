// shou.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("瘦頭陀", ({ "shou toutuo", "shou" ,"toutuo"}));
	set("nickname",HIR "遼東瘦尊者" NOR);
	set("long","這頭陀身材奇矮，而且胖得出奇，整個人就活脫脫是一個大冬瓜。\n光溜溜的腦袋上瞪着一對銅鈴大眼，樣子非常滑稽，全身宛如個肉球。\n衣飾偏又十分華貴，長袍馬褂都是錦緞。\n臉上五官擠在一起，倒是給人硬生生的搓成了一團。\n");
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi", 2000);
	set("qi", 2000);
	set("max_jing", 1000);
	set("jing", 1000);
	set("combat_exp", 400000);
	set("score", 30000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("leg", 80);
	set_skill("strike", 80);
	set_skill("staff", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("yixingbu", 120);
	set_skill("jueming-leg", 120);
	set_skill("huagu-mianzhang", 120);
	set_skill("dulong-dafa", 70);
	set_skill("shenlong-staff", 120);

	map_skill("force", "dulong-dafa");
	map_skill("leg", "jueming-leg");
	map_skill("strike", "huagu-mianzhang");
	map_skill("staff", "shenlong-staff");
	map_skill("parry", "shenlong-bashi");
	map_skill("dodge", "yixingbu");
	prepare_skill("leg", "jueming-leg");
	prepare_skill("strike", "huagu-mianzhang");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang2" :),		
		(: perform_action, "staff.chang3" :),		
		(: perform_action, "strike.hua" :),
		(: perform_action, "strike.baigu" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("party/party_name", HIY"神龍教"NOR);
	set("party/rank", HIC"右護法"NOR);
	set("party/level", 2);
	create_family("神龍教", 2, "弟子");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 50);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"洪安通" : "這三個字是你說的嗎？",
		"洪教主" : "洪教主仙福永享，壽與天齊，洪教主神目如電，燭照四方。",
		"蘇荃"   : "沒規沒矩的。",
		"神龍島" : "神龍島在汝州的東北方向，從塘沽口出海便到。",
		"神龍教" : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龍教的(join shenlongjiao)。\n",
		"教主"   : "教主脾氣不好，要討他歡心纔好。\n",
		"口號"   : "萬年不老！永享仙福！壽與天齊！文武仁聖！\n",
	]) );
	setup();
	carry_object(CLOTH_DIR"jinduan")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
	add_money("silver", 30);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "神龍教" NOR ) {
		command("say 你不是本教教衆， 想來找死啊！");
		return;
	}
	if ((int)ob->query("shen") > 0 ) {
		command("say 我神龍教與世隔絕，向來不與您這種白道人物打交道，您請回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/shenlong/shenlong.h"; 
