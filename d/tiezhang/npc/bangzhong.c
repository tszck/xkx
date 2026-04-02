// Last Modified by winder on Nov. 17 2000
// bangzhong.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("黑衣幫衆", ({ "heiyi bangzhong", "heiyi", "bangzhong"}));
	set("long",
		"他是一個身行健壯的漢子，兩臂粗壯，膀闊腰圓。滿臉的兇相。\n");
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set_skill("force", 40);
	set_skill("guiyuan-tunafa", 40);
	set_skill("dodge", 40);
	set_skill("shuishangpiao", 40);
	set_skill("spear", 40);
	set_skill("tiexue-qiang", 40);
	set_skill("strike", 40);
	set_skill("zhusha-zhang", 40);
	set_skill("parry", 40);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("spear", "tiexue-qiang");
	map_skill("strike", "zhusha-zhang");
	map_skill("parry", "tiexue-qiang");
	prepare_skill("strike", "zhusha-zhang");

	setup();
	carry_object(__DIR__"obj/heiyi")->wear();
	carry_object(WEAPON_DIR+"spear/tieqiang")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("tiezhang ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "鐵掌幫" ) )
	{
		if( !ob->query_temp("warned") )
		{
			command("say 站住！你不是鐵掌幫弟子，不能在此久留！！");
			command("say 識相的就快滾，惹得爺爺火起，打斷你的狗腿！！");
			command("hehe");
			ob->set_temp("warned", 1);
		}
		else
		{
			if( ob->query_temp("stay") < 3) ob->add_temp("stay", 1);
			else
			{
				command( "say 你活得不耐煩了，竟敢到鐵掌幫來撒野！！！\n");
				remove_call_out("hiting_ob");
				call_out("hiting_ob", 1, ob);
			}
		}
	}
}
int hiting_ob(object ob)
{
	object me;
	me=this_object();
	me->set_leader(ob);
	ob->kill_ob(me);
        me->fight_ob(ob);
	remove_call_out("moving_ob");
	call_out("moving_ob",1,ob);
}
