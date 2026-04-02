// bear.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(BLK"黑熊"NOR, ({ "hei xiong", "bear","xiong" }) );
	set("race", "走獸");
        set("age", 20);
        set("long", "一隻兇猛的黑熊，形體碩大，人立而行。\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 250);
        set_temp("apply/armor", 100);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "黑熊衝着你搖頭擺尾地，不知道是什麼意思。\n",
                "黑熊擠了擠鼻子，你覺得它好象在笑，頓時一陣緊張。\n",
        }) );
}

void die()
{
	object ob, corpse;
	message_vision("$N震天動地一聲慘嚎，慢慢委頓在地，死了！\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	if(uptime() > 300)
	{
		ob = new("/clone/medicine/nostrum/xiongdan");
		ob->move(corpse);
	}
	corpse->move(environment(this_object()));
	destruct(this_object());
}
