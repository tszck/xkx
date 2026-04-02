// tiji.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("天驕", ({ "tiji"}));
	set("gender", "男性");
	set("class", "bonze");
	set("title", HIR"學士"HIG"明教"HIC"風字門教眾"NOR"天下名俠之一代天驕少林派掌門大師兄"NOR);
	set("nickname", HIY"清燈佛影印菩提"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("少林派" ,37, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
