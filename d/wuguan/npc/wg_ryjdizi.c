inherit NPC;
#include <ansi.h>

void create()
{
       set_name("日月神教弟子", ({ "riyuejiao dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個日月神教的弟子。\n");
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
			say( "日月神教弟子說道：這位" + RANK_D->query_respect(ob)
            + "想加入日月神教嗎，可以看"BRED"(help riyuejiao)"NOR"。\n");
			break;
		case 1:
			say( "日月神教弟子得意地說道：東方教主的武功天下間無人能及。\n");
			break;
		case 2:
			say( "日月神教弟子高喊道：東方教主，千秋萬載，一統江湖。\n");
			break;
	}

}
