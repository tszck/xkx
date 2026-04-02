//wpp.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("展昭", ({ "wpp"}));
	set("gender", "男性");
	set("class", "taoist");
	set("title", HIW"聖人"HIG"明教風字門教衆"NOR"武林泰斗武當派掌門大師兄");
	set("nickname", HIW"玉貓"HIR"南俠"NOR);
	set("age", 51);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 13);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 25);
	set("weiwang", 30);
	create_family("武當派" ,2, "弟子");	
	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}
