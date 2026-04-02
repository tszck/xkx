// wangerniang.c 王二孃 
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;

void create()
{
	set_name("王二孃", ({ "wang erniang", "wang", "erniang" }) );
	set("gender", "女性" );
	set("age", 53);
	set("long", "她看來有50多歲了，但是徐娘半老，風韻尤存。\n");
	set("combat_exp", 7000);
	set("attitude", "friendly");
	set("rank_info/respect", "王二孃");	
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	add_money("silver",20);
}

