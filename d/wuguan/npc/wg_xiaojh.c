
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("小叫化", ({ "xiao jiaohua", "xiao" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一個很機靈的小叫化，穿的破破爛爛。\n");
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
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(3) ) {
		case 0:
			say( "小叫化歪着頭，説道：這位" + RANK_D->query_respect(ob)
                   + "，想加入我們丐幫嗎，可以看"BRED"(help gaibang)"NOR"。\n");
			break;
		case 1:
			say( "小叫化眉飛色舞的説道： 天下第一幫麼, 自然是我們丐幫了。
 降龍十八掌，打狗棒是我們丐幫的絕學。\n");
			break;
		case 2:
			say( "小叫化眉飛色舞的説道： 天下第一幫麼, 自然是我們丐幫了。
丐幫暗道四通八達，唯有本幫弟子才能使用。\n");
			break;	
	}

}
