// cow.c

inherit NPC;

void create()
{
        set_name("水牛", ({ "shui niu", "niu", "cow" }));
        set("long","一頭南方山區常見的水牛，是耕作的主力，也用來拉車載物。由於水草茂盛，長得十分肥壯。\n");
	set("race", "走畜");
        set("age", 5);
        set("int", 30);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
}


void die()
{
	object ob, corpse;
	message_vision("$N發出哞地一聲，靜靜倒在地上死去了。\n",this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/niuhuang");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
