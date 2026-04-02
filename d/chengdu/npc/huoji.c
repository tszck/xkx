// Room: /d/chengdu/npc/huoji.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("夥計", ({ "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他看起來有幾分力氣，做事挺勤快的。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		JEWELRY_DIR"necklace",
		JEWELRY_DIR"goldring",
	}));

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

