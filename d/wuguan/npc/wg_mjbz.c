
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("明教幫眾", ({ "mingjiao bangzhong", "bangzhong" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個身強力壯漢子。\n");
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
			say( "明教幫眾説道：天下第一教, 就是我們明教。。這位" + RANK_D->query_respect(ob)
              + "，若想入明教，可以看"BRED"(help mingjiao)"NOR"。\n");
			break;
		case 1:
			say( "明教幫眾説道：乾坤大挪移，聖火令神功可是獨步武林的絕學啊。\n");
			break;
		case 2:
			say( "明教幫眾説道：本教四大護教法王各有一種護身絕技！\n");
			break;	
	}

}
