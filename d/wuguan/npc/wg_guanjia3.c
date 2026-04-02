
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("馬房管事", ({ "mafang guanshi", "guanshi" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long",
		"他是揚州武館的一個小管家，專管馬房裏的大小雜事！\n");
	set("combat_exp", 55000);
	set("attitude", "friendly");
	set("inquiry", ([
		"打掃馬房" : "你就在這老老實實給我打掃馬房，沒有我的滿意，你別想回去覆命！",
		"打掃"     : "你就在這老老實實給我打掃馬房，沒有我的滿意，你別想回去覆命！",
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
	 
	if(ob->query_temp("job_name")!="打掃馬房") return; 

	if (!( present("saozhou", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say 你還沒領工具吧，去東物品房找老李要。 \n");
		return;
	}

	if(!(ob->query_temp("job_name")!="打掃馬房"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"，你就在這打掃(sao 馬房)吧。\n");
    }
}
