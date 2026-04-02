// chushi.c
// Last Modified by winder on Sep. 27 2001

inherit NPC;
string ask_me();

void create()
{
	set_name("廚師", ({ "chu shi", "chu" }));
	set("title", "梅莊");
	set("long",
		"梅莊的一名廚師，笑眯眯地看着你，看來很和善的樣子。\n");
	set("gender", "男性");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);

	set("max_qi", 200);
	set("max_jing", 50);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	set("combat_exp", 500);
	set("shen",0);
	set("score", 0);
	set("no_get",1);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("parry", 10);

	set("inquiry", ([
		"喫飯" : (: ask_me :),
	]));
	setup();
}

string ask_me()
{       mapping fam;
 
 
 

	object me=this_player();
	if(!(fam = me->query("family")) || fam["family_name"] != "黑木崖")
		return RANK_D->query_respect(me) + "與本派素無來往，不知此話從何談起？";

	me->set("food", (int)me->max_food_capacity());
	me->set("water", (int)me->max_water_capacity());

	return "慢慢喫！別噎住了。";
}
