//   zhanglang.c

inherit NPC;
void create()
{
        set_name("蟑螂", ({ "zhang lang","lang" }) );
	set("race", "昆蟲");
	set("subrace", "爬蟲");
        set("age", 4);
        set("per", 10);
        set("long", "一隻令人噁心的小蟲子，正好奇的看着你。\n");
        set("combat_exp", 60);
        set("attitude", "friendly");
        set_skill("dodge", 5);
        set_skill("unarmed", 5);
        set_skill("parry", 5);
        set("max_qi", 100);
        set("chat_chance",10);
        set("chat_msg",({
            "嘰嘰...嘰嘰嘰嘰，....嘰嘰嘰..~~~~。\n",
 //       (:random_move:)
        }));

        setup();
}
