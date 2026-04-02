// Last Modified by winder on May. 29 2001
// Npc: /d/nanshaolin/npc/hg-toutuo.c

inherit NPC;

void create()
{
	set_name("火工頭陀", ({ "huogong toutuo", "huogong", "toutuo" }));
	set("long", "這是一個混身被燻得漆黑的負責劈柴，生火的火工頭陀。\n");
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
        create_family("南少林派", 22, "弟子");
	setup();
}

