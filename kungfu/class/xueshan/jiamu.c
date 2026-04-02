// /kungfu/class/xueshan/jiamu.c  嘉木活佛
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("嘉木活佛", ({ "jiamu huofo", "huofo", "jiamu" }));
        set("long",@LONG
嘉木活佛是雪山寺有道的高僧，對佛法有精深的研究。
他身穿一件黃色袈裟，頭帶僧帽。目光如電，似乎身懷絕技。
LONG
        );
        set("title",HIY"活佛"NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1000); 
        set("max_jing", 2500); 
        set("neili", 2000); 
        set("max_neili", 2000); 
        set("jiali", 50); 
        set("combat_exp", 400000); 
        set("score", 40000); 

        set_skill("lamaism", 120);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 110);
        set_skill("dodge", 130);
        set_skill("shenkong-xing", 180);
        set_skill("unarmed", 120);
        set_skill("yujiamu-quan", 180);
        set_skill("parry", 120);
        set_skill("sword", 130);
        set_skill("mingwang-jian", 180);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        
        set("env/wimpy", 60);

        create_family("雪山寺", 3, "活佛");
        set("class", "lama");

        setup();

	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"seng-shoe")->wear();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",20);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修習密宗內功需要純陽之體。");
                command("say 這位" + RANK_D->query_respect(ob) +
                        "還是請回吧！");
                return;
        }

        if ((string)ob->query("class") != "lama") {
                command("say 我西藏黃教門內的清規戒律甚多。");
                command("say 這位" + RANK_D->query_respect(ob) +
                        "還是請回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 這位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，還是請回吧！");
                return;
        }

        if ((int)ob->query_skill("lamaism", 1) < 60) {
                command("say 入我雪山寺，修習密宗心法是首要的。");
                command("say 這位" + RANK_D->query_respect(ob) +
                        "是否還應該多多鑽研本門的心法？");
                return;
        }

        command("smile");
        command("nod");
        command("say 你就隨我學習佛法吧！");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY "大喇嘛" NOR);
}
