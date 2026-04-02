// huoji.c
inherit NPC;

void create()
{
	set_name("客店夥計", ({ "kedian huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18+random(20));
	set("long", "他是小客店的夥計。\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("chat_chance", 3);
	set("chat_msg", ({
		"夥計説道：你...你...你可別殺我啊，我是良...良民。\n",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

