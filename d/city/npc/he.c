// he.c

inherit NPC;

void create()
{
	set_name("何員外", ({ "he yuanwai", "he" }));
	set("shen_type", -1);

	set("gender", "男性" );
	set("age", 53);
	set("long", "何員外是揚州城裏的首富，和當地的官紳都有很深的交情。\n");
	set("combat_exp", 400);
	set("attitude", "friendly");
	setup();

	carry_object(__DIR__"obj/choucloth")->wear();
}

void init()
{	
	object ob; 
  
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("何員外奇怪地對你說道：“你這人怎麼隨隨便便地就跑到我的園子裏來？”\n");
}