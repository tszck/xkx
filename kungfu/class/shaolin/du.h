// du.h for fight and apprentice to 3-du

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "與本派素無來往，不知此話從何談起？");
		return;
	}

	if ((string)ob->query("class") != "bonze" && ob_fam["family_name"] == "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺內學藝。");
		return;
	}

	if (ob_fam["generation"] <= my_fam["generation"])
	{
		command("say " + RANK_D->query_respect(ob) + "，貧僧哪裏敢當 !");
		return;
	}

	if (ob_fam["generation"] == (my_fam["generation"] + 1))
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麼跑到我這兒來了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if (ob_fam["generation"] == (my_fam["generation"] + 2))
	{
		if (ob->query_temp("3du-ok") == 1)
		{
			ob->delete_temp("3du-ok");

			if (ob->query_skill("dodge", 1) >= 120 &&
				ob->query_skill("force", 1) >= 120 &&
				ob->query_skill("parry", 1) >= 120 &&
				ob->query_skill("buddhism", 1) >= 120)
			{
				command("say 你能過金剛伏魔圈，哈哈哈 !");
				command("say 貧僧又得一可塑之才，真是可喜可賀 !");

				name = ob->query("name");
				new_name = "玄" + name[1..1];
				ob->set("name", new_name);

				command("say 從今以後你的法名叫做" + new_name + "，恭喜你榮升爲少林派玄字輩弟子 !");
				command("recruit " + ob->query("id"));
			}
			else
				command("say 貧僧要收的是有用之才，你還是回去向你師父學習吧!");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "，沒能過金剛伏魔圈，我不想收你。");
			return;
		}
	}
	return;
}
