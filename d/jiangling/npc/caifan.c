//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("菜販", ({"cai fan", "fan"}));
	set("long", "一個賣菜的小販，挑了一擔綠油油的空心菜。\n");
	set("gender", "男性");
	set("age", 24);
	set("combat_exp", 1000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}


