
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("古墓女弟子", ({ "gumu dizi", "dizi" }) );
       set("gender", "女性" );
       set("age", 16);
       set("long",
               "這是是一位古墓女弟子，一身白衣。。\n");
       set("combat_exp", 30500);
       set("attitude", "friendly");
 
       setup();

       carry_object("/clone/cloth/cloth/moon-dress")->wear();
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
			say( "古墓女弟子微微笑着説道：這位" + RANK_D->query_respect(ob)
          + "，若想入古墓清修，可以看"BRED"(help gumu)"NOR"。\n");
			break;
		case 1:
			say( "古墓女弟子説道：古墓派清塵脫俗，容貌欠佳者還是及早拜
入其它門派為好。\n");
			break;
		case 2:
			say( "古墓女弟子自語道：聽説師姐們已經成為了神鵰大俠的傳人，
古墓派弟子應當耐得住寂寞，奮發努力，重興古墓。\n");
			break;
	}

}
