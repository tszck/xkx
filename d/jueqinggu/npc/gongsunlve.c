// Room: /d/jueqinggu/npc/gongsunlve.c
// Last Modified by winder on Feb. 17 2001

inherit NPC;

void create()
{
	set_name("公孫綠萼", ({ "gongsun lve", "gongsun", "lve" }));
	set("long",
		"她眉目清雅，眼神清澈，膚色白裏泛紅，嘴角邊有粒小小黑痣。看上去自有一般清靈之氣。\n");
	set("gender", "女性");
	set("age", 18);
	set("attitude", "friendly");
	set("shen", 3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 1000);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 80);
	set("combat_exp", 300000);

	set_skill("force", 100);
	set_skill("xuantian-wuji", 100);
	set_skill("dodge", 100);
	set_skill("kunlun-shenfa", 104);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi-jian", 100);
	set_skill("throwing", 100);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("sword", "liangyi-jian");
	set("inquiry", ([
		"絕情丹": "丹藥好象只有兩顆了，而且我父親收藏的很嚴密。",
		"情花": "有些外表美麗的，往往是有毒的。",
	]) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

 
