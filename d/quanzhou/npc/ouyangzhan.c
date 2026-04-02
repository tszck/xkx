// ouyangzhan.c 歐陽詹

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("歐陽詹", ({ "ouyang zhan", "zhan", "ouyang" }));
	set("long",
"歐陽詹是泉州名士。\n");
	set("gender", "男性");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 4000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱")) return 0;
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
 
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 1000)
	{
		message_vision("歐陽詹同意指點$N一些讀書寫字的問題。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		return 1;
	}
}
