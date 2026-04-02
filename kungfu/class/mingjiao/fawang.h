// fawang.h for fight and get letter from FaWang

void attempt_apprentice(object ob)
{
 

	if (ob->query("party/party_name") != HIG "明教" NOR)
	{
		command("say " + RANK_D->query_respect(ob) + "與本教素無來往，不知此話從何談起？");
		return;
	}
	else
	{
		command("say 本法王又得一可塑之才，真是可喜可賀 !");
		command("recruit " + ob->query("id"));
//		ob->set("title", HIR"明教護法"NOR);
	}
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
		       	command("say 恭喜你榮升為明教護法！");
 				    ob->set("title", HIR"明教護法"NOR);
 				  }
}
#include "mingjiao.h"