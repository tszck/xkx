
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("木房管事", ({ "mufang guanshi", "guanshi" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long", "他是揚州武館的一個小管家，專管木房！\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("inquiry", ([
		"鋸木頭" : "你就在這老老實實給我鋸木頭，沒有我的滿意，你別想回去覆命！",
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
	 
	if(ob->query_temp("job_name")!="鋸木頭") return; 

	if (!( present("juzi", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say 你還沒領工具吧，去東物品房找老李要。 \n");
		return;
	}
	if(!(ob->query_temp("job_name")!="鋸木頭"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"，你就在這鋸木頭(ju 木頭)吧。\n");
	}
}
