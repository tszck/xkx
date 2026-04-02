// ahda.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("阿達", ({ "ahda" }));
	set("title", HIM"電視臺保安"NOR);
	set("shen_type", 1);

	set("gender", "男性" );
	set("long", @LONG
這是一個穿着保安制服的大漢，身高七尺，窮兇極惡的樣子。
阿達很兇惡地告訴你："請問你找誰？電視臺閒人免近"。
LONG);
	set("nickname", HIY"農村第一庶民警察"NOR);
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 200);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("combat_exp", 5000000);
	set_skill("force", 300);
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 300);
	set_skill("taiji-quan", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 300);
	set_skill("taoism", 250);
	set_skill("literate", 300);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	setup();

        carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}