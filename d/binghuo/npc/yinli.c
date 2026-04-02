// yinli.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("殷離", ({ "yin li", "yin", "li"}));
        set("long",
            "她是張無忌的表妹，殷野王的女兒，一張秀麗的臉蛋因爲練千蛛萬毒
手的武功，變得浮腫不堪。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 12);
        set("str", 15);
        set("int", 25);
        set("con", 25);
        set("dex", 30);

        set("max_qi", 500);
        set("max_jing", 200);
        set("max_neili", 500);
        set("jiali", 50);
        set("combat_exp", 50000+random(10000));
        set("score", 20000);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("qianzhu-wandushou", 70);
        set_skill("qingfu-shenfa",50);
        map_skill("dodge", "qingfu-shenfa");
        map_skill("parry", "qianzhu-wandushou");
        map_skill("unarmed", "qianzhu-wandushou");

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 15);
        set("inquiry", ([
            "張無忌" :  "你是問阿牛哥嗎？",
            "阿牛"   :  "這個狠心短命的......",
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}
