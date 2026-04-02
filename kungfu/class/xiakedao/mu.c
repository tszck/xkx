//mu.c
#include <ansi.h>
inherit NPC;
int ask_zhou();

void create()
{
        set_name("木島主", ( { "mu daozhu", "mu" }) );
        set("title", HIB"俠客島島主"NOR);
        set("gender", "男性" );
        set("age", 60);
        set("long","這是個看起來五十來歲的漢子，面眉全白，臉傍消瘦，着一襲白袍，昂然挺立。\n");

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);
        set("no_get",1);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set("qi",20000);
        set("max_qi", 20000);
        set("jing", 20000);
        set("max_jing", 20000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 300);
        set("combat_exp", 3000000);
        set("score", 250000);

        set_skill("force", 300);
        set_skill("taixuan-gong", 300);
        set_skill("dodge", 300);
        set_skill("tiyunzong", 300);
        set_skill("unarmed", 300);
        set_skill("taiji-quan", 300);
        set_skill("parry", 300);
        set_skill("taoism", 200);
        set_skill("literate", 100);

        map_skill("force", "taixuan-gong");
        map_skill("dodge", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
        map_skill("parry", "taixuan-gong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "木島主忽然一怕腦袋，說：臘八粥可是好東西哇！\n",
            "木島主說道：怎麼這麼多的英雄也不能領悟太玄經呢。\n",
        }) );
        set("inquiry", ([
            "臘八粥" : (: ask_zhou :),
            "俠客島" :  "\n這個島是我和龍兄弟無意中發現的。\n",
        ]));
        create_family("俠客島", 1, "島主");
        setup();

 //       carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if(ob->query_skill("literate",1)>50)
              say ("木島主看着你搖了搖頭，說道：讀書太多。\n");
        return;
}

int ask_zhou()
{
        say(
"\n木島主對你說：這是本島特有的東西，它主要由一味'斷腸蝕骨腐心草'構成，\n"
"要開花後效力方著，但這種草每十年纔開一次花，所以臘八粥很名貴，\n"
"一般人很難得到的，小兄弟想要就要看你的緣分了！\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\n木島主搖頭道：這不是我想要的呀！\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("木島主搖頭道：我看小兄弟今生於此無緣。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\n木島主見是賞善罰惡簿，大喜道：恭喜這位小兄弟了!\n",who);
                                obn=new("/clone/medicine/nostrum/labazhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\n木島主見是賞善罰惡簿，對$N搖頭道：賞善罰惡簿我有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","木島主看見賞善罰惡簿，大喜道：現在只差腐心草了。\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("木島主搖頭道：我看小兄弟今生於此無緣。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\n木島主見是腐心草，大喜道：恭喜這位小兄弟了!\n",who);
                                obn=new("/clone/medicine/nostrum/labazhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\n木島主見是腐心草，對$N搖頭道：腐心草我已經有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","木島主看見腐心草，大喜道：現在只差賞善罰惡簿了。\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
        return 1;
}

int recognize_apprentice(object ob)
{

        message_vision("$N搖了搖頭。\n",this_object());
        command("tell "+ob->query("id")+"我是不收弟子的，你可以到石室中自學哇！\n");
        return 0;
}
int accept_hit(object me)
{
	command("say 年輕人本性好勝，卻也須分場合。");
	return notify_fail("");
}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}

int accept_fight(object ob)
{
        object me;
        me = this_object();
        if (me->is_fighting())
         {
         	command("say 我正在比武中，請稍後。\n");
         	return notify_fail("");
         	}
        if(me->query("eff_qi") < me->query("max_qi") || 
           me->query("qi") < me->query("eff_qi") ||
           me->query("neili") < me->query("max_neili")){
           me->set("eff_qi",me->query("max_qi"));
           me->set("qi",me->query("max_qi"));
           me->set("neili",me->query("max_neili"));
           }
        if( ob->query_temp("pending/fight") ) {
        ob->delete_temp("pending/fight");
        message_vision(CYN"$n對$N說：好吧，讓我看看你是否有資格學太玄神功。\n"NOR, ob, me);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        if (!ob->is_busy())
        ob->start_busy(1);
        return 1;
        }
        else return 0;
}
int checking(object me, object ob)
{
        object good;
        int my_max_qi, his_max_qi;
           seteuid(getuid());
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting()){
                call_out("checking",1, me, ob);
                return 1;
                }
        if ( !present(ob, environment()) ) return 1; 
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
        	  ob->set_temp("winner",1);
            message_vision("$N對$n不住地讚歎：這位"+RANK_D->query_respect(ob)+"果然不同凡響，你可以試着學習太玄神功了。\n"NOR, me, ob);
            return 1;
            }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ){
                message_vision("$N衝着$n微笑道：你的功力尚淺，還需多努力啊。\n"NOR, me,ob);
                return 1;
               }
        return 1;
}