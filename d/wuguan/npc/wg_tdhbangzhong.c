inherit NPC;
#include <ansi.h>

void create()
{
       set_name("天地會幫衆", ({ "tiandihui bangzhong", "bangzhong" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個身材矮小的天地會幫衆。\n");
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
			say( "天地會幫衆說道：這位" + RANK_D->query_respect(ob)
            + "想加入天地會嗎，可以看"BRED"(help tiandihui)"NOR"。\n");
			break;
		case 1:
			say( "天地會幫衆說道：加入天地會即成爲反抗清廷的義士。\n");
			break;
		case 2:
			say( "天地會幫衆說道：總舵主陳近南的成名絕技，凝血神抓威震江湖，宵小之輩望風披靡。\n");
			break;
	}

}
