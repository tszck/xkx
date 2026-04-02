// /kungfu/class/baituo/ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

int ask_help();
int do_accept();

void create()
{
	set_name("歐陽鋒", ({ "ouyang", "feng" }));
	set("long", "他是白駝山莊主，號稱“西毒”的歐陽鋒。\n"
		   +"由於習練「九陰真經」走火入魔，已變得精\n"
		   +"神錯亂，整日披頭散髮。\n");
	set("title", "白駝山莊主");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIR "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("unarmed", 170);
	set_skill("dodge", 200);
	set_skill("parry", 180);
	set_skill("hand",170);
	set_skill("training",200);
	set_skill("staff", 200);
	set_skill("hamagong", 200);
	set_skill("chanchu-bufa", 170);
	set_skill("shexing-diaoshou", 200);
	set_skill("lingshe-zhangfa", 180);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family("白駝山派",1, "開山祖師");
	set("chat_chance",2);
	set("chat_msg",({
		"歐陽鋒自言自語道：何日白駝山派才能重霸江湖呢…\n",
		"歐陽鋒道：我兒歐陽克必能夠重振白駝山派雄風！\n",
		"歐陽鋒道：江湖險惡，困難重重哪！\n",
	}));
	setup();
	carry_object("/d/baituo/obj/shezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",50);
}

void init()
{
}

void attempt_apprentice(object ob)
{
	message_vision("歐陽鋒瞪了$N一眼道：“我白駝山不世藝業豈可輕傳。”\n", ob); 	
}


