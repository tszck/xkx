
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("武當道童", ({ "daotong", "tong" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一個十七八歲的小道童，一幅天真的樣子。\n");
       set("combat_exp", 2500);
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
			say( "武當道童笑嘻嘻地說道：這位" + RANK_D->query_respect(ob)
          + "，想加入武當的話，可以看"BRED"(help wudang)"NOR"。\n");          
			break;
		case 1:
			say( "武當道童喃喃自語道：上次看見張真人已經是一年前了，想來他老人家
 武功境界更加深不可測了，江湖誰不對武當派刮目向待呢。\n");
			break;
		case 2:
			say( "武當道童得意地說道：我武當派的人蔘果是萬木之祖，喫了對內力修爲大有好處。\n");
			break;	
	
	}

}
