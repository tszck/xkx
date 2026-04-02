// laofu.c 老虎
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("孟加拉虎", ({ "mengjiala hu", "tiger","hu" }) );
	set("race", "走獸");
        set("age", 20);
        set("long", "一隻斑斕孟加拉虎，雄偉極了。\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 50000);
        set("neili",800);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 10000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "孟加拉在浚巡，嚇得你大氣都不敢出。\n",
                "孟加拉仰天長嘯，聲震山谷，黃葉紛墜。\n",
        }) );
}

void die()
{
	object ob, corpse;
	message_vision("$N發出震天動地的一聲長嘯，轟地倒在地上，死了！\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/hugu");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
