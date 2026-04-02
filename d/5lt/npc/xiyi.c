// ahda.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("蜥蜴", ({ "xiyi" }));
	set("title", "民間工藝品店店主");
	set("shen_type", 1);

	set("gender", "男性" );
	set("long", @LONG
店主是一個文弱書生，他正輕搖摺扇，衝你點頭微笑。
LONG);
	set("nickname", HIY"愛在蜥元前"NOR);
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	setup();

        carry_object(__DIR__"obj/pen")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}