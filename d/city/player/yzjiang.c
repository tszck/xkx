//yzjiang.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("長江", ({ "yzjiang"}));
	set("gender", "男性");
	set("class", "fighter");
	set("title", "白駝山派第二代弟子");
	set("nickname", HIY"昔時人已沒 "NOR HIR" 今日水猶寒"NOR);
	set("age", 28);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	create_family("白駝山派" ,2, "弟子");	
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
