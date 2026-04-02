inherit NPC;
#include <ansi.h>

void create()
{
       set_name("華山弟子", ({ "huashan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個清秀的華山弟子。\n");
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
			say( "華山派弟子說道：這位" + RANK_D->query_respect(ob)
            + "想加入華山派嗎，可以看"BRED"(help huashan)"NOR"。\n");
			break;
		case 1:
			say( "華山派弟子說道：無招勝有招，敵強我更強。獨孤九劍不含招式，有招既無招，
無招亦有招。\n");
			break;
		case 2:
			say( "華山派弟子說道：我們華山武功博大精深，你如能學得一二，就能出人頭地了。\n");
			break;
	}

}
