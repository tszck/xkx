// NPC /d/npc/caihuashe.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("菜花蛇", ({ "caihua she", "she" }) );
	set("race", "爬蛇");
	set("age", 1);
	set("long", "一隻青幽幽的菜花蛇，頭部呈橢圓形。\n");
	set("attitude", "peaceful");
	set("str", 15);
	set("cor", 16);
	set("combat_exp", 100+random(50));
	set_temp("apply/attack", 7);
	set_temp("apply/damage", 4);
	set_temp("apply/defence",6);
	set_temp("apply/armor",5);
	setup();
}

void die()
{
	object ob;
	message_vision("$N抽搐兩下，$N死了。\n", this_object());
	ob = new(__DIR__"obj/sherou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
