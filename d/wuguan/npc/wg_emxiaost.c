
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("峨嵋小師太", ({ "xiao shitai", "xiao" }) );
       set("gender", "女性" );
       set("age", 16);
       set("long",
               "這是是一位峨嵋的小師太，長的眉清目秀。\n");
       set("combat_exp", 40500);
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
			say( "小師太微微笑着説道：善哉，善哉，這位" + RANK_D->query_respect(ob)
          + "，若想入峨嵋清修，可以看"BRED"(help emei)"NOR"。\n");
			break;
		case 1:
			say( "小師太微笑道：峨嵋功夫清秀獨特，臨濟十二莊為內功中的絕學。
 雁行刀，迴風拂柳劍，各各威力無窮。\n");
			break;
		case 2:
			say( "小師太微笑道：若能貫通幽冥二莊便可到達武林人士夢寐以求的龍虎交會、
水火既濟的境界、並熟通採製靈丹之妙法。\n");
			break;	
	}

}
