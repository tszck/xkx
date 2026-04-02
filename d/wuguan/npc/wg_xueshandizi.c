inherit NPC;
#include <ansi.h>

void create()
{
       set_name("雪山弟子", ({ "xueshan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個年青的雪山弟子。\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(3) ) {
		case 0:
			say( "雪山派弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入雪山派嗎，可以看"BRED"(help mizong)"NOR"。\n");
			break;
		case 1:
			say( "雪山派弟子説道：本門的火焰刀是天下間最霸道的功夫。\n");
			break;
		case 2:
			say( "雪山派弟子説道：我們雪山武功博大精深，你如能學得一二，就能出人頭地了。\n");
			break;
	}

}
