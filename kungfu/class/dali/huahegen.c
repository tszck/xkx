// huahegen.c 華赫艮

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("華赫艮", ({ "hua hegen", "hua" }));
	set("title",  "大理司徒" );
	set("long", "他是大理國三大公之一。
華司徒本名阿根，出身貧賤，現今在大理國位列三公，未發跡時，幹
部的卻是盜墓掘墳的勾當，  最擅長的本領是偷盜王公巨賈的墳墓。這些富貴人物
死後，必有珍異寶物殉葬，華阿根從極遠處挖掘地道，通入墳墓，然後盜取寶物。
所花的一和雖巨，卻由此而從未為人發覺。有一次他掘入一墳，在棺木中得到了一
本殉葬的武功祕訣，依法修習，練成了一身卓絕的外門功夫，便捨棄了這下賤的營
生，輔佐保定帝，累立奇功，終於升到司徒之職。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	set("env/wimpy", 60);	
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("score", 200000);

        set_skill("force", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("cuff", 95);
        set_skill("sword", 80);
        set_skill("staff", 80);
	set_skill("kurong-changong", 80);
        set_skill("tiannan-step", 135);
        set_skill("jinyu-quan", 145);
        set_skill("duanjia-sword", 120);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("大理段家",19,"武將");
}

int accept_object(object who, object ob)
{
	object tool;
	if (ob->id("axiang letter")) 
	{
		tell_object(who, "你給華赫艮一封阿祥的信。\n");
		tell_object(who, "華赫艮拆開信看了看，點頭説道：“既然是阿祥寫信來，我就把東西給你吧。”\n");
		destruct(ob);
		tool = new("/d/suzhou/npc/obj/diggertools");
		tool->move(who);
		tell_object(who, "華赫艮給你一套盜墓工具。\n");
		return notify_fail("華赫艮收了阿祥的信。");
	}
	return 0;
}

