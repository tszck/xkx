// /kungfu/class/xueshan/daerba.c  達而巴
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("達而巴", ({ "daerba huofo", "huofo" }));
        set("long",@LONG
他是金輪法王座下的大弟子。深得法王的真傳。
身穿一件黃色袈裟，頭帶僧帽。
LONG
        );
        set("title", HIY "活佛" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 1200);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("score", 150000);

        set_skill("lamaism", 80);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 120);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 150);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 150);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang-jian", 100);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        
        set("env/wimpy", 60);

        create_family("雪山寺", 3, "活佛");
        set("class", "lama");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("gold",1);
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

        command("say 你就是我的弟子了！");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY "大喇嘛" NOR);
}
