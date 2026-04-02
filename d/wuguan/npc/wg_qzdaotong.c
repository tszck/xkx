
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("全真道童", ({ "daotong", "tong" }) );
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
			say( "全真道童含笑道：這位" + RANK_D->query_respect(ob)
          + "，想加入全真教的話，可以看"BRED"(help quanzhen)"NOR"。\n");
			break;
		case 1:
			say( "全真道童得意地説道：祖師王重陽，又號「中神通」，首次華山
論劍，連敗東邪、西毒、南帝、北丐，奪得武功天下第一的稱號。\n");
			break;
		case 2:			
			say( "全真道童喃喃自語道：修習先天功後，練得玄門定陽丹可以長內力，妙用無窮哦。\n");			
			break;	
	}

}
