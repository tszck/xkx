inherit NPC;
#include <ansi.h>

void create()
{
       set_name("逍遙弟子", ({ "xiaoyao dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個清秀的逍遙弟子。\n");
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
			say( "逍遙派弟子説道：這位" + RANK_D->query_respect(ob)
            + "想加入逍遙派嗎，可以看"BRED"(help xiaoyao)"NOR"。\n");
			break;
		case 1:
			say( "逍遙派弟子説道：凌波微步，按伏羲六十四卦而排，內勁行遍一周天，
腳步亦踏遍六十四卦一周天。步法輕靈迅捷，有如凌波而行，羅襪生塵，巧妙已極。\n");
			break;
		case 2:
			say( "逍遙派弟子説道：北冥神功博大精深，天羽奇劍曼妙非凡，學成之後定可獨步武林。\n");
			break;
	}

}
