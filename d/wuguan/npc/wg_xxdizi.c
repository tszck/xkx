inherit NPC;
#include <ansi.h>

void create()
{
       set_name("星宿弟子", ({ "xingxiu dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long", "他是一個滿臉瘴氣的星宿弟子。\n");
       set("combat_exp", 25000);
       set("attitude", "friendly");
       setup();
        carry_object("clone/cloth/cloth")->wear();

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
		case 0: say("星宿弟子嘿嘿說道：加入星宿，心慈手軟可不行。這位"+RANK_D->query_respect(ob)
+"，想通的話，可以看"BRED"(help xingxiu)"NOR"。\n");
			break;
		case 1: say("星宿弟子嘿嘿說道：化功大法吸人真元，可把別人辛辛苦苦練練來的功力化爲己有，此
乃天下第一險毒的武功。哈哈哈..........\n");
			break;	
		case 2: say("星宿弟子奸笑道：如果被我們星宿的抽髓掌打中，非要哀號數月而死。\n");
			break;
	}

}
