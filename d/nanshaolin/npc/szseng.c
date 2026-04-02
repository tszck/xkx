// Npc: /d/nanshaolin/npc/szseng.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>
string ask_job();

void create()
{
	set_name("侍粥僧", ({ "shizhou seng", "shizhou","seng" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "他膀大腰圓，看來長年從事體力勞動！\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", 
	([
		"熬粥" : (: ask_job :),
	]));
        create_family("南少林派", 22, "弟子");
	setup();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
string ask_job()
{
	object ob = this_player();

	if (ob->query("combat_exp")>=30000)
		return ("你已經有了基礎了，沒必要再找我來領活了。\n");
	if ((string)ob->query("family/family_name")!="南少林派")
		return ("非南少林弟子不能領工作。");
	if (ob->query_temp("job_name"))
		return ("你不是已經領了工作嗎？還不快去做。\n");
	ob->set_temp("job_name","熬粥");
		return "做僧侶就要能喫苦耐勞，你就幫我熬粥"HIR"(ao 粥)"HIC"吧。";
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("job_name")!="熬粥") return; 
	if(!(ob->query_temp("job_name")!="熬粥"))   
	{
		command("stare "+ob->query("id"));
		command("say " + RANK_D->query_respect(ob)+"，來替我幫忙"HIR"(ao 粥)"HIC"真是多謝你了!!!\n");
	}
}
