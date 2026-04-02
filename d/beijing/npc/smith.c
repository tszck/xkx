// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("鐵匠", ({ "tiejiang", "smith" }));
	set("title", "鐵匠鋪老闆");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "鐵匠正用鐵鉗夾住一塊紅熱的鐵塊放進爐中。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		WEAPON_DIR"changjian",
		WEAPON_DIR"gangdao",
		WEAPON_DIR"hammer",
		"/d/beijing/obj/tudao",
		"/d/xingxiu/obj/tiegun",
	}));

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
