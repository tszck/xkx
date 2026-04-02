
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("桃花島弟子", ({ "taohuadao dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一個清秀的桃花島弟子。\n");
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
			say( "桃花島弟子説道：這位" + RANK_D->query_respect(ob)
            + "加入桃花島，可以看"BRED"(help taohua)"NOR"。\n");
			break;
		case 1:
			say( "桃花島弟子説道：這位" + RANK_D->query_respect(ob)
            + "加入桃花島，學會蘭花拂穴手和彈指神通兩大絕藝，縱橫江湖為日不遠了。\n");
			break;
		case 2:
			say( "桃花島弟子説道：我們島主黃藥師琴棋書畫無所不精，他老人家的功夫
 你如能學得一二，就能出人頭地了。\n");
			break;
	}

}
