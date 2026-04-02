// Npc: /kungfu/class/shaolin/da-mo.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>

void create()
{
	set_name("達摩老祖", ({
		"da mo",
		"da",
		"mo",
	}));
	set("long",
		"他是一位捲髮絡腮須的天竺老僧，身穿一襲邋遢金絲繡紅袈裟。\n"
		"但卻滿面紅光，目蘊慈笑，眼現智珠，一派得道高僧氣勢。\n"
                "他就是少林派開山鼻祖、當今武林的隱世高僧達摩祖師。\n"
	);

	set("title", HIR"少林開山祖師"NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 80);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3500);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("buddhism", 180);
	set_skill("literate", 130);

	set_skill("blade", 200);
	set_skill("claw", 200);
	set_skill("club", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("force", 200);
	set_skill("hand", 200);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("whip", 200);

	set_skill("banruo-zhang", 300);
	set_skill("cibei-dao", 300);
	set_skill("damo-jian", 300);
	set_skill("fengyun-shou", 300);
	set_skill("fumo-jian", 300);
	set_skill("hunyuan-yiqi", 200);
	set_skill("jingang-quan", 300);
	set_skill("longzhua-gong", 300);
	set_skill("luohan-quan", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("pudu-zhang", 300);
	set_skill("qianye-shou", 300);
	set_skill("sanhua-zhang", 300);
	set_skill("riyue-bian", 300);
	set_skill("shaolin-shenfa", 300);
	set_skill("weituo-gun", 300);
	set_skill("wuchang-zhang", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("yingzhua-gong", 300);
	set_skill("yijinjing", 250);
	set_skill("yizhi-chan", 300);
	set_skill("zui-gun", 300);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("少林派", 34, "弟子");
	setup();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	object me;
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "與本派素無來往，不知此話從何談起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺內學藝。");
		return;
	}

	if ( ob_fam["generation"] != 36 )
	{
		command("say " + RANK_D->query_respect(ob) + "，貧僧哪裏敢當 !");
		return;
	}

        if ((ob->query_int() < 40) || (ob->query("PKS") > 3 ))
        {
                command("say 萬事都講一個緣字。");
                command("say " + RANK_D->query_respect(ob) + "與佛無緣，還是請回吧。");
		return;
	}

	if (ob->query_skill("dodge",1)>=150 &&
		ob->query_skill("force",1)>=150 &&
		ob->query_skill("parry",1)>=150 &&
		ob->query_skill("buddhism",1)>=150)
	{
		command("say 老衲又得一可塑之才，真是大暢老懷 !");
		name = ob->query("name");
		new_name = "渡" + name[1..1];
		ob->set("name", new_name);

		command("say 從今以後你的法名叫做" + new_name + "，恭喜你榮升為少林派渡字輩弟子 !");
		command("recruit " + ob->query("id"));
	}
	else
		command("say 你現在就來找我也太早了點吧 !");
	return;
}
