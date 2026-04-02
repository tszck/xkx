inherit NPC;
#include <ansi.h>

void create()
{
       set_name("白駝弟子", ({ "baituo dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一位相貌古怪的白駝山弟子。\n");
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
			say( "白駝山弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入白駝山嗎，可以看"BRED"(help baituo)"NOR"。\n");
			break;
		case 1:
			say( "白駝山弟子説道：掌門西毒歐陽鋒的獨門絕技蛤蟆功乃是天下武學中的絕頂功夫，
其中內功變化精微，奧妙無窮；外功掌法則剛中有柔，柔中有剛，招式奇特且威力巨大。\n");
			break;
		case 2:
			say( "白駝山弟子説道：少莊主歐陽克風流成性，終日在揚州城內遊逛，你可以拜他，
然後他會把你帶到白駝山。\n");
			break;
	}

}
