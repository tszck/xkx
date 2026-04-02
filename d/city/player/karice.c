// karice.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("靈米", ({ "karice"}));
	set("gender", "男性");
	set("class", "beggar");
	set("title", "崑崙派第三代弟子");
	set("nickname", HIR"一生一火花"NOR);
	set("age", 26);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("崑崙派" , 3, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

