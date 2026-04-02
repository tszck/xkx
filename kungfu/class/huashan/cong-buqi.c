// cong-buqi.c  叢不棄
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("叢不棄", ({ "cong buqi", "cong" }) );
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "華山劍宗第十三代弟子");
        set("age", 52);
        set("long",
                "叢不棄是華山劍宗高手。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 4000);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set("env/wimpy", 60);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feilong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 100);
        set_skill("huashan-sword", 180);
        set_skill("kuangfeng-jian", 180);
        set_skill("huashan-neigong", 130);
        set_skill("huashan-ken", 180);
//        set_skill("huashan-zhangfa", 80);
        set_skill("huashan-shenfa", 180);

        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "huashan-sword");
        map_skill("force", "huashan-neigong");
//        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("華山派劍宗", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say 老夫不想收徒。");
}
