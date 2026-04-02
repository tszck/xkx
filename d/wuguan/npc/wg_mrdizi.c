// Last Modified by Sir on 9/17/2001
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("慕容弟子", ({ "murong dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一個很年青的少年，但是身強力壯。\n");
       set("combat_exp", 30000);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/cloth/cloth")->wear();
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
			say( "慕容弟子正顏道：慕容山莊是武林人人景仰的地方。這位" + RANK_D->query_respect(ob)
             + "，何不來投我慕容山莊，可以看"BRED"(help murong)"NOR"。\n");
			break;
		case 1:
			say( "慕容弟子正顏道：若能入我慕容山莊的還施水閣和琅繯玉洞，定可學到
驚世駭俗的武功。\n");
			break;
		case 2:
			say( "慕容弟子正顏道：慕容山莊是武林人人景仰的地方。這位" + RANK_D->query_respect(ob)
             + "，何不來我慕容山莊，他日定能學成鬥轉星移的絕世武功，獨步武林。\n");
			break;	
	}

}
