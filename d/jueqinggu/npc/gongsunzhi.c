// Room: /d/jueqinggu/npc/gongsunzhi.c
// Last Modified by winder on Feb. 17 2001

inherit NPC;

void create()
{
	set_name("公孫止", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long",
		"面目英俊，透出軒軒高舉之概，只是面色蠟黃，容顏枯槁。\n");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "friendly");
	set("shen", -7000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 1000);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("combat_exp", 700000);

	set_skill("force", 150);
	set_skill("xuantian-wuji", 150);
	set_skill("dodge", 150);
	set_skill("kunlun-shenfa", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("liangyi-jian", 150);
	set_skill("throwing", 150);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("sword", "liangyi-jian");
	set("inquiry", ([
		"絕情丹": "丹藥無多，而且也很難煉製，非萬不得已。。。",
//		"情花": "有些外表美麗的，往往是有毒的。",
	]) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

 
