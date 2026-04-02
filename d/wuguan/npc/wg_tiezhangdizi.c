inherit NPC;
#include <ansi.h>

void create()
{
       set_name("鐵掌幫弟子", ({ "tiezhang dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "一個一臉陰沉的鐵掌幫弟子。\n");
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
			say( "鐵掌幫弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入鐵掌幫嗎，可以看"BRED"(help tiezhang)"NOR"。\n");
			break;
		case 1:
			say( "鐵掌幫弟子説道：本幫每代幫主臨終之時，必帶着他心愛的寶刀寶劍、珍物古玩上峯，
一代又復一代，石室中寶物自是不少。。\n");
			break;
		case 2:
			say( "鐵掌幫弟子説道：本幫以鐵掌馳名天下，掌力渾厚惡毒，與降龍十八掌、黯然銷魂掌並稱
天下。\n");
			break;
	}

}
