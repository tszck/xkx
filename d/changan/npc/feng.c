// zhu.c 朱熹

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("馮從吾", ({ "feng congwu", "feng" }));
	set("long",
"馮先生是當代大學者，精通儒術。\n");
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

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/馮"))
		return 0;
	ob->add_temp("mark/馮", -1);
	return 1;
}

int accept_object(object who, object ob)
{
 
	if (!(int)who->query_temp("mark/馮"))
		who->set_temp("mark/馮", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("馮從吾同意指點$N一些讀書寫字的問題。\n", who);
		who->add_temp("mark/馮", ob->value() / 50);
		return 1;
	}
}
