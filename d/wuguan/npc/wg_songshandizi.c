inherit NPC;
#include <ansi.h>

void create()
{
       set_name("嵩山弟子", ({ "songshan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個年青的嵩山弟子。\n");
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
			say( "嵩山派弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入嵩山派嗎，可以看"BRED"(help songshan)"NOR"。\n");
			break;
		case 1:
			say( "嵩山派弟子説道：五嶽劍派共由江湖中的五大門派組成，即：恆山派、華山派、嵩山派、
衡山派及泰山派。我嵩山派為五嶽劍派盟主。\n");
			break;
		case 2:
			say( "嵩山派弟子説道：我們嵩山劍法博大精深，你如能學得一二，就能出人頭地了。\n");
			break;
	}

}
