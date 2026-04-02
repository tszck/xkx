// Room: /d/chengdu/npc/poorman.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("壯漢", ({ "man"}) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "一個體格強壯的漢子。\n");
	set("attitude", "friendly");
	set("combat_exp", 750);
//	set("shen", 50);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 18);
	set("con", 17);
	set("int", 13);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"壯漢伸手打了個哈哈。\n",
		"壯漢伸手捉住了身上的蝨子，罵道：老子身上沒幾兩肉，全叫你們給咬了。 \n",
		(: random_move :)
	}) );
	carry_object(CLOTH_DIR"cloth")->wear();
}

