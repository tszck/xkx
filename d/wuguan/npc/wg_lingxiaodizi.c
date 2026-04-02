inherit NPC;
#include <ansi.h>

void create()
{
       set_name("凌霄弟子", ({ "lingxiao dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個清秀的凌霄弟子。\n");
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
			say( "凌霄弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入凌霄城嗎，可以看"BRED"(help lingxiao)"NOR"。\n");
			break;
		case 1:
			say( "凌霄弟子説道：凌霄劍法劍劍精妙，招招鋒鋭，獨步武林。\n");
			break;
		case 2:
			say( "凌霄弟子説道：拜得凌霄城掌門“威德先生”為師，成為“凌霄城城主”。
那時，你亦可以傲視武林了。。\n");
			break;
	}

}
