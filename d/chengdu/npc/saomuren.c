// Room: /d/chengdu/npc/saomuren.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("掃墓人", ({ "saomu ren", "ren" }));
	set("long","這是個眼帶憂鬱的掃墓人，他不停地在那裏唉聲嘆氣，不知道搞什麼鬼。\n");
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 44);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 10);
	set("combat_exp", 2000);
	set("score", 100);

	set_skill("force", 12);
	set_skill("dodge", 12);
	set_skill("unarmed", 12);
	set_skill("parry", 12);

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}

