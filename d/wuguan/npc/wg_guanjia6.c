
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("菜園管事", ({ "caiyuan guanshi", "guanshi" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long", "他是揚州武館的一個小管家，專管菜園裏大小雜事！\n");
	set("combat_exp", 52500);
	set("attitude", "friendly");
	set("inquiry", ([
		"澆水" : "你就在這老老實實給我澆水，沒有我的滿意，你別想回去覆命！",
	]) );
	setup();

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
	if( !ob || environment(ob) != environment() ) return;
	 
	if(ob->query_temp("job_name")!="澆菜地") return; 

	if (!( present("piao", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say 你還沒領工具吧，去東物品房找老李要。 \n");
		return;
	}

	if(!(ob->query_temp("job_name")!="澆菜地"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"，你就在這澆水(jiao 水)吧。\n");
    }
}
