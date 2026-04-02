// huoji. 藥鋪夥計

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("小夥計", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是青蛙從城鄉結合部招來幫忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/medicine/nostrum/sanhuangwan",
		"/clone/medicine/nostrum/huanzhidan",
		"/clone/medicine/nostrum/heishidan",
		"/clone/medicine/nostrum/jinchuang",
		"/clone/medicine/nostrum/yangjing",
		"/clone/medicine/nostrum/dust",
		"/clone/medicine/vegetable/xionghuang",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
