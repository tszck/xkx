// singleblue.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("細胳膊鹿", ({ "singleblue" }));
	set("title", HIM"電視臺祕書"NOR);
	set("shen_type", 1);

	set("gender", "女性" );
	set("long", @LONG
細胳膊鹿懶得理你，繼續埋頭寫作業。
LONG);
	set("nickname", HIW"腦子有小包"NOR);
	set("age", 20);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	set("combat_exp", 1000000);
	setup();

	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}