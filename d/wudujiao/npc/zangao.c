// zangao.c
inherit NPC;
#include <ansi.h>

string *first_name = ({"藏"});
string *name_words = ({ "獒"});


void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name,({"zang ao","ao"}));
	set("race", "走獸");
        set("long", "一隻兇猛的藏獒，正警覺的來回踱步。\n");
        set("age", 5);
        set("attitude", "peaceful");

        set("max_jing", 1000);
        set("max_qi", 1000);

        set("str", 30);
        set("cor", 50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 50);
        set("combat_exp", 150000);

        setup();
}
void init()
{
        object me;
        add_action("do_train", "xun");
        if (interactive(me = this_player()))
        {
                if((string)me->query("family/family_name")!="五毒教")
                {
                         remove_call_out("kill_ob");
                         call_out("kill_ob", 1, me);
                }
        }
        ::init();
}

int do_train(string arg)
{
        object me,who;
        me =this_object();
        who=this_player();
        if (!arg || (arg != "zang ao"))
                return notify_fail("你要馴服什麼？\n");

        if(me->is_fighting())
                return notify_fail("這隻藏獒正在戰鬥。\n");
        if((string)who->query("family/family_name")!="五毒教")
                return notify_fail("什麼？\n");

        message_vision("藏獒本來就是人馴養的，你有沒有搞錯哦？\n\n", who,me);
        return 1;
}
