// chu.h 處字輩收徒

int accept_object(object ob, object obj)
{
	object me = this_object();

	if (obj->query("id")=="quanzhen xin2" && ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 好，"+ob->query("name")+"，你願意拜我為師嗎？");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say 這東西給我可沒有什麼用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");
	string name, new_name;
	name = ob->query("name");

	if ((int)ob->query_skill("xiantian-qigong",1) < 70 ) {
		command("say 你的本門內功心法火候不足,難以領略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 10000) {
		command( "say 行俠仗義是我輩本份，你若能多做些俠義之事，我一定收你為徒。\n");
		return;
	}
        if (ob->query("gender")=="男性" && me->query("gender")=="女性") {
                command("say 我不收男徒，你還是去拜我幾位師兄為師吧。\n");
                return;
        }
	if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "全真教")
	{
		command("say 我教為玄門正宗，" + RANK_D->query_respect(ob) + "若要學藝，還是先找本門四代弟子吧。");
		return;
	}
	if ( ob_fam["generation"] == 0 )
	{
		command("say 無量壽佛！你還是先找四代弟子學點基本功吧。");
		return;
	}
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"，貧道哪裏敢當！");
		return;
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 1))
	{
		command("say 我和"+ob_fam["master_name"]+"搶徒弟，哈哈哈！");
		command("recruit " + ob->query("id"));
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");

			command("say 是"+ob_fam["master_name"]+"叫你來找我的？好，好。");
			command("say 貧道看你是可塑之才，你就安心學藝吧！");
			if(ob->query("class") == "quanzhen")
			{
				new_name = name[0..0] + "志" + name[2..2];
				ob->set("name", new_name);
				command("say 從今以後你的道號叫做"+new_name+ "，你現在是全真教志字輩弟子了。");
			}
			else command("say 你沒有出家，我雖可以收你，以後你可別後悔了。");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，你沒有推薦信，不能越級拜師。");
			return;
		}
	}
	return;
}
