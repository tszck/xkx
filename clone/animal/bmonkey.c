// /d/shenlong/npc/bmonkey.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

int do_drink(string);

void create()
{
	set_name("老猴子", ({ "monkey", "hou", "houzi" }) );
	set("race", "走獸");
	set("age", 200 + random(50));
	set("long", "一隻老態龍鍾的老猴子，雖然動作遲緩，但絲毫不減狡詐的性子。\n");
	set("attitude", "peaceful");

	set("limbs", ({ "頭部", "身體",  "前腿", "後腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

// make sure those shenlong dizis can not catch it without using tricks
	set("combat_exp", 50000 + random(50000));
	set_temp("apply/attack", 30 + random(20));
	set_temp("apply/defense", 30 + random(20));
	set_temp("apply/damage", 30 + random(20));
	set_temp("apply/armor", 30 + random(20));

	setup();

// do not want to speak to leak secret information
}

void init()
{
	object me = this_object();
	object ob = this_player();

	::init();

	if( interactive(ob) && living(ob) )
	{
// this monkey is not for shenlong newbies to get exp
		if( ob->query("combat_exp") < 10000 )
		{
			COMBAT_D->do_attack(me, ob); 
			COMBAT_D->do_attack(me, ob);
			if( random(6) > 3 ) COMBAT_D->do_attack(me, ob);
			kill_ob(ob);}
		else {		       
			message_vision("老猴子被$N嚇了一跳，趕緊躲在一旁。\n", me);
			command("look " + ob->query("id"));
		}
	}

	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_object();
	object ob = this_player();
	object *inv;

	if( me->is_fighting() || me->is_busy() )
		return 1;

	if( !(arg == "jiudai" || arg == "wineskin" || arg == "skin") )
	{
		command("? " + ob->query("id"));
		return 1;
	}
	
	inv = all_inventory(environment(me));
	for( int i = 0; i < sizeof(inv); i++)  {
// it is smart enough to pick up the one which has alcohol
// do you believe it? i believe it because it has a nose
		if( inv[i]->query("id") == "jiudai" && inv[i]->query("liquid/type") == "alcohol" ) {
			command("get " + inv[i]->query("id"));
			if( !inv[i]->query("liquid/remaining") ) {
				say("老猴子搖了搖" + inv[i]->query("name") + "後，失望地搖了搖頭。\n");
				say("老猴子用力一甩，把" + inv[i]->query("name") + "掄得無影無蹤。\n");
				destruct(inv[i]);
			} else {
				say("老猴子高興得吱吱亂叫，一口全喝了下去。\n");
				inv[i]->set("liquid/remaining", 0);
				command("drop " + inv[i]->query("id"));
				say("老猴子看起來有點力不從心，搖搖欲墜。\n");
				set_temp("drunk", 1);
				add_temp("apply/attack", -20);
				add_temp("apply/defense", -20);
				add_temp("apply/damage", -20);
				remove_call_out("del_drunk");
				call_out("del_drunk", 10 + random(10));
				return 1;
			} 
		}
	}

	command("angry " + ob->query("id"));
	return 1;
}
			
void del_drunk()
{
	object me = this_object();

	if( !me ) return;
	if( query_temp("drunk") ) {
	       delete_temp("drunk"); 
	       add_temp("apply/attack", 20);
	       add_temp("apply/defense", 20);
	       add_temp("apply/damage", 20);
	}
}			

void die()
{
	object ob, obj;

	ob = new("/d/shenlong/obj/hougan");
	ob->move(environment());

	if( objectp(obj = this_object()->query_temp("last_damage_from")) )
	ob->set("owner", obj->query("id"));

	message_vision("$N慘嚎一聲，死了！\n", this_object());
	destruct(this_object());
}


