// maoniu.c 犛牛

inherit NPC;

void create()
{
	set_name("犛牛", ({ "mao niu", "niu" ,"yak"}) );
	set("race", "走畜");
	set("age", 5);
	set("long", "一隻身強體壯的犛牛，全身長着長毛，似乎在覓食。\n");
	set("attitude", "peaceful");
	set("str",60);
	set("max_qi",1000);
	set("qi",1000);
	set("max_jing",1000);
	set("jing",1000);
	set("combat_exp", 50000);

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 500);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 100);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N發出哞地一聲哀鳴，靜靜倒在地上死去。\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/niuhuang");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
