// duck.c

inherit NPC;

void create()
{
        set_name("野鴨", ({ "duck" }) );
	set("race", "飛禽");
        set("age", 1);
        set("long", "一隻野鴨。\n");

        set("combat_exp", 500);

        setup();
}

