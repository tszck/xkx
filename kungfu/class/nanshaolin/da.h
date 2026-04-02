// da.h 大字輩收徒
void attempt_apprentice(object ob)
{
	object me=this_object();
	mapping ob_fam, my_fam;
	string name, new_name;
	my_fam =me->query("family");
	name = ob->query("name");

	if(!(ob_fam=ob->query("family")) || ob_fam["family_name"]!="南少林派")
	{
		command("say "+RANK_D->query_respect(ob)+"與本派素無來往，不知此話從何談起？");
		return;
	}
	if( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"，貧僧哪裏敢當！");
		return;
	}
	if( ob->query_skill("force", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"，你的基本內功還需要磨練。貧僧到時再收你爲徒。");
		return;
	}
	if( ob->query_skill("zhanzhuang-gong", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"，你的站樁功還需要磨練。貧僧到時再收你爲徒。");
		return;
	}
	if( ob_fam["generation"]==(my_fam["generation"]+1) )
	{
		command("say "+ob_fam["master_name"]+"的徒弟怎麼跑到我這兒來了，哈哈哈！");
		command("recruit "+ob->query("id"));
	}
	if( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		command("say 老衲得一可塑之才，真是老懷大暢。");
		command("recruit " + ob->query("id"));
		if( ob->query("class") == "bonze")
		{
			name = ob->query("name");
			new_name = "元" + name[1..1];
			ob->set("name", new_name);
			command("say 今後你的法名叫做"+new_name+"。\n");
		}
		else ob->set("title", "南少林俗家第二十弟子");
	}
	else
		command("say "+RANK_D->query_respect(ob)+"，你是從哪蹦出來的，你不能越級拜師。");
	return;
}
