
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("小和尚", ({ "xiao heshang", "xiao" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一個十七八歲的小和尚，一幅循規蹈矩的樣子。\n");
       set("combat_exp", 10500);
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
                call_out("greeting", 0, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "少林小和尚笑嘻嘻地説道：這位" + RANK_D->query_respect(ob)
           + "，想加入少林的話，可以看"BRED"(help shaolin)"NOR"。\n");
			break;
		case 1:
			say( "少林小和尚微笑道：天下功夫出少林，江湖中人有幾個敢去
 少林寺惹是生非。達摩老祖傳下來的武學絕技可不是嚇唬人的。\n");
			break;
	}

}
