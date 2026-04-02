// xiaohuozi.c 小夥子
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;

void create()
{
	set_name("小夥子", ({ "xiao huozi", "xiao" }));
	set("gender", "男性");
	set("age", 19);
	set("long","他是一個在釀酒屋打工的年輕人，長的牛高馬大，看上去有些力氣。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
	add_money("silver",2);
}
