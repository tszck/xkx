// Last Modified by winder on May. 29 2001
// fang.h 方字輩收徒

void attempt_apprentice(object ob)
{
	mapping fam;
	if(mapp(fam = ob->query("family")) &&
		fam["family_name"]=="南少林派" &&
		fam["generation"] < 22)
	{
		command("say 阿彌陀佛。我佛慈悲。\n");
		return;
	}
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿彌陀佛！貧僧就收下你做『俗家弟子』了。");
	}
	command("say 阿彌陀佛，善哉！善哉！");
	command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
	if( (string)ob->query("class")!="bonze" )
	{
		ob->set("title", "南少林俗家第二十二弟子");
	}

 				  }
}