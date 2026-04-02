// eagleg.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
        set_name("禿鷹", ({ "eagle" }) );
	set("race", "飛禽");
        set("age", 3);
        set("long", "一隻黑色的禿鷹，禿頭黑羽，好喫腐屍，看起來討厭極了。\n");
        set("attitude", "peaceful");

        set("combat_exp", 3000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        setup();
}
