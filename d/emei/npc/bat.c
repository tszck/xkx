//bat.c 蝙蝠

inherit NPC;

void create()
{
        set_name("蝙蝠", ({"bianfu","bat"}) );
	set("race", "飛禽");
        set("age", 8);
        set("long", "這是一隻蝙蝠，正倒掛在洞頂。\n");

        set("str", 40);
        set("dex", 50);

        set_temp("apply/attack", 33);
        set_temp("apply/armor", 20);

        set("chat_chance", 2);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "蝙蝠撲撲地飛過來，在你頭上轉了一圈，又飛走了。\n",
         }) );

        setup();
}
