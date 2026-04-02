
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("水房管事", ({ "shuifang guanshi", "guanshi" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long", "他是揚州武館的一個小管家，專管水房裏的大小雜事！\n");
	set("combat_exp", 52500);
	set("attitude", "friendly");
	set("inquiry", ([
		"挑水" : "你就在這老老實實挑水，不挑滿所有的缸，你就別想回去覆命！",
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
	 
	if(ob->query_temp("job_name")!="挑水") return; 

	if (!( present("shuitong", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say 你還沒領工具吧，去東物品房找老李要。 \n");
		return;
	}

	if(!(ob->query_temp("job_name")!="挑水"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"，你就在這挑水(tiao 水)吧。\n");
	}
}

