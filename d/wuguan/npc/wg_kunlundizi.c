inherit NPC;
#include <ansi.h>

void create()
{
       set_name("崑崙弟子", ({ "kunlun dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個彪悍的崑崙弟子。\n");
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
			say( "崑崙派弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入崑崙派嗎，可以看"BRED"(help kunlun)"NOR"。\n");
			break;
		case 1:
			say( "崑崙派弟子説道：習得本派拳腿雙絕，定可笑傲武林。\n");
			break;
		case 2:
			say( "崑崙派弟子説道：祖師“崑崙三聖”何足道文武雙全，刀槍劍戟，拳掌氣功，琴棋
書畫、詩歌詞賦，無一不凌駕古今，冠絕天下。\n");
			break;
	}

}
