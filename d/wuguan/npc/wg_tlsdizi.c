
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("天龍寺弟子", ({ "tianlongsi dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 18);
       set("long",
               "他是一個天龍寺的小師傅。\n");
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
			say( "天龍寺弟子説道：這位" + RANK_D->query_respect(ob)
          + "加入大理天龍寺的話，可以看"BRED"(help dali)"NOR"。\n");
			break;
		case 1:
			say( "天龍寺弟子説道：一陽指，枯榮禪功可是佛門絕學，你要是再能學到六脈神劍的話，
  必能傲視羣雄。\n");
			break;
		case 2:
			say( "天龍寺弟子説道：大理茶花天下聞名，練功之餘去茶花園賞賞花、品品茶，倒也不失
為一件樂事。\n");
			break;	
	}
}
