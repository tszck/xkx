// Npc: /kungfu/class/shaolin/xuan-nan.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("玄難大師", ({
		"xuannan dashi",
		"xuannan",
		"dashi",
	}));
	set("long",
		"他是一位白鬚白眉的老僧，身穿一襲銀絲棕黃袈裟。他身材極瘦，\n"
		"兩手更象雞爪一樣。他雙目微閉，一副沒精打採的模樣。\n"
	);


	set("nickname", "般若堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 180);
	set_skill("parry", 120);
	set_skill("cuff", 120);
	set_skill("staff", 120);
	set_skill("finger", 120);
	set_skill("strike", 120);
	set_skill("jingang-quan", 180);
	set_skill("wuchang-zhang", 180);
	set_skill("yizhi-chan", 180);
	set_skill("banruo-zhang", 180);
	set_skill("buddhism", 120);
	set_skill("literate", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("finger", "yizhi-chan");
	map_skill("strike", "banruo-zhang");
	map_skill("staff", "wuchang-zhang");
	map_skill("parry", "banruo-zhang");

	prepare_skill("finger", "yizhi-chan");
	prepare_skill("strike", "banruo-zhang");
	
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"十八羅漢陣"       : (: ask_me :),
		"羅漢大陣"	   : (: ask_me :)
	]));

	setup();

        carry_object("/clone/weapon/wczhang")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


#include "/kungfu/class/shaolin/xuan-nan.h"

