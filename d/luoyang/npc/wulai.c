// wulai.c 無賴

inherit NPC;

void create()
{
	set_name("無賴", ({ "wu lai", "wulai" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一個成天遊手好閒的無賴，賭錢賭得兩眼紅腫、臉色灰暗。\n");
	set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
