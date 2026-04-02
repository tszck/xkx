inherit NPC;
#include <ansi.h>

void create()
{
       set_name("恆山女尼", ({ "hengshan nvni", "nvni" }) );
       set("gender", "女性" );
       set("age", 26);
       set("long",
               "這是是一位恆山的小師太，長的眉清目秀。\n");
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
			say( "恆山女尼微笑着說道：這位" + RANK_D->query_respect(ob)
            + "想入我恆山派嗎，可以看"BRED"(help hengshan)"NOR"。\n");
			break;
		case 1:
			say( "恆山女尼說道：恆山派爲五嶽劍派中的一支，武功以劍法爲主，
手上功夫更爲武林一絕。\n");
			break;
		case 2:
			say( "恆山女尼正顏道：“恆山三定”威鎮江湖，宵小之輩無不聞風而逃。
恆山弟子若得三位師太真傳，學成之日定能傲視武林。\n");
			break;
	}

}
