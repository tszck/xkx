inherit NPC;
#include <ansi.h>

void create()
{
       set_name("泰山弟子", ({ "taishan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個英俊的泰山弟子。\n");
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
			say( "泰山派弟子說道：這位" + RANK_D->query_respect(ob)
            + "想加入泰山派嗎，可以看"BRED"(help taishan)"NOR"。\n");
			break;
		case 1:
			say( "泰山派弟子說道：入我泰山方可習得江湖中唯一百發百中的絕招“岱宗如何”。\n");
			break;
		case 2:
			say( "泰山派弟子說道：泰山派自百年前東靈祖師立派以來，代有才人，功夫自可傲立江湖。\n");
			break;
	}

}
