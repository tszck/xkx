// Last Modified by winder on May. 29 2001
// tian.h 天字輩收徒

int do_nod();
void attempt_apprentice(object ob)
{
        mapping fam;

	if(!mapp(fam = ob->query("family")) || fam["family_name"]!="南少林派")
	{
		command("say 我只收本派弟子爲徒。\n");
		return;
	}
	if(fam["generation"] < 19)
	{
		command("say 阿彌陀佛。我佛慈悲。\n");
		return;
	}
	if(fam["generation"] > 20)
	{
		command("say 貧僧不收低輩弟子。阿彌陀佛。\n");
		return;
	}
	ob->set_temp("wait_nod", 1);
	command("say 依照南少林寺歷代規矩，"+RANK_D->query_respect(ob)+"你必須接下我十招，我才能收你爲徒。你願意麼？那就點個頭吧(nod)。");
}
int do_nod()
{
	object ob = this_player();

	if(!ob->query_temp("wait_nod")) return 0;
	ob->delete_temp("wait_nod");
	call_out("test", 1, ob);
	return 0;
}
void test(object ob)
{
	object me=this_object();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	call_out("check", 1, ob);
}

void check(object ob)
{
	string new_name;

	if (!living(ob) || environment(ob) != environment() ||
		ob->query("max_qi") > ob->query("qi") * 2)
	{
		command("sigh");
		return;
	}
	else
	{
		command("recruit " + ob->query("id"));
		if( ob->query("class") == "bonze")
		{
			new_name=ob->query("name");
			new_name[0..0] = "大";
			ob->set("name", new_name);
			command("say 從今以後你的法名叫做"+new_name+ "，恭喜你榮升爲我南少林派大字輩聖僧！\n");
		}
		else ob->set("title", "南少林俗家第十九弟子");
	}
	return;
}
