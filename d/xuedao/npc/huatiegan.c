// huatiegan.c

inherit NPC;
#include <ansi.h>
void create()
{
       set_name("花鐵幹", ({ "Hua tiegan", "hua" }));
       set("long", 
       "他就是南四奇“落花流水”中的老二。\n"
       "南四奇橫行江南，行俠仗義，花鐵幹一手中平槍，號稱中平無敵。可是他的爲人卻不咋的。\n");
       set("gender", "男性");
       set("title", "南四奇");
       set("nickname", HIR"中平無敵"NOR);
       set("age", 45);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 700000);
       set("shen_type", 0);

       set_skill("force", 100);
       set_skill("huashan-neigong", 100);
       set_skill("dodge", 100);
       set_skill("lingxu-bu", 100);
       set_skill("unarmed", 100);
       set_skill("huashan-ken", 100);
       set_skill("parry", 100);
       set_skill("spear", 100);
       set_skill("zhongping-qiang", 100);
       set_skill("literate", 40);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "lingxu-bu");
       map_skill("unarmed", "huashan-ken");
       map_skill("spear", "zhongping-qiang");
       map_skill("parry", "zhongping-qiang");
       set("chat_chance", 20);
       set("chat_msg", ({
              "花鐵幹緩緩提起中氣，嘯聲如潮湧出：“落花～～流水……”震人耳饋。\n",
       }));

       setup();
       carry_object("/clone/weapon/changqiang")->wield();
}

