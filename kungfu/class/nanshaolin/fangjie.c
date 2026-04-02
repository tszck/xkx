// Last Modified by winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/fangjie.c

inherit NPC;
inherit F_MASTER;
mixed carry_water();

void create()
{
	set_name("方戒", ({ "fang jie", "fang", "jie"}));
	set("long",
		"他是一位精神抖擻的中年和尚，身穿一襲青布鑲邊袈裟。身材略高，\n"
		"太陽穴微凸，雙目炯炯有神。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("leg", 50);
	set_skill("shaolin-leg", 50);
	set_skill("staff", 50);
	set_skill("pudu-staff", 50);
	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "shaolin-cuff");
	map_skill("leg", "shaolin-leg");
	map_skill("staff", "pudu-staff");
	map_skill("parry", "pudu-staff");
	prepare_skill("cuff", "shaolin-cuff");
	prepare_skill("leg", "shaolin-leg");

	set("inquiry", ([
		"挑水":	(: carry_water :)
	]));
	create_family("南少林派", 21, "弟子");
	setup();

	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"staff/chanzhang")->wield();
}

mixed carry_water()
{
	object me = this_player();
	object ob = this_object();

	if (!me->query("carry_count"))
		if (present("liao kao", me))
		{
			destruct(present("liao kao", me));
			return "你的活已經幹完了，我幫你解開鐐銬。";
		}
		else
			return RANK_D->query_respect(me) + "不是開玩笑吧？";
	if (present("tie tong", me))
		return "你不是拿着鐵桶嗎？快去幹活吧。";
	if (present("tie tong", environment()))
		return "鐵桶不是在地上放着嗎？拿去幹活吧。";
	command("buddhi");
	new("/d/nanshaolin/obj/tie-tong")->move(environment());
	command("say 這是幹活的傢什，拿去用吧。");
	message_vision("$N從身後拿出一對大鐵桶放在地上。\n", ob);
	return 1;
}

#include "/kungfu/class/nanshaolin/fang.h";
