inherit NPC;
#include <ansi.h>

void create()
{
       set_name("紅花會幫衆", ({ "honghuahui bangzhong", "bangzhong" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個身材魁梧的紅花會幫衆。\n");
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
			say( "紅花會幫衆說道：這位" + RANK_D->query_respect(ob)
            + "想加入紅花會嗎，可以看"BRED"(help honghua)"NOR"。\n");
			break;
		case 1:
			say( "紅花會幫衆說道：七十二路追魂奪命劍天下無雙，是二當家無塵道長的得意武功。\n");
			break;
		case 2:
			say( "紅花會幫衆說道：總舵主陳家洛的成名絕技，落花十三劍威震江湖，宵小之輩望風披靡。\n");
			break;
	}

}
