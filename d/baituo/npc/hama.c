// hama.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("蟾蜍", ({ "chan chu", "chu", "hama" }) );
	set("race", "野獸");
	set("age", 10);
	set("long", "一隻肥大的蟾蜍，趴在地上一動不動。\n");
	set("attitude", "peaceful");	
	set("limbs", ({ "頭部", "身體", "後肢", "肚皮" }) );
	set("verbs", ({ "hoof"}) );
	set("combat_exp", 1900);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 8);
	set_temp("apply/armor", 8);
	setup();
}

void init()
{
	object ob = this_player();
	::init();
	if (interactive(ob) && !ob->query_skill("hamagong", 1))
	{
		this_object()->kill_ob(this_player());
	}
}
int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + 3);
	return 0;
}
