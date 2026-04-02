// laohu2.c
inherit NPC;
#include <ansi.h>

string *first_name = ({"小"});
string *name_words = ({ "虎崽"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name,({"hu zai"}));

	set("race", "走獸");
        set("long", "一隻剛出生幾個月的小老虎，正和同伴們撲打遊戲。\n");
        set("age", 1);
        set("attitude", "peaceful");

        set("max_jing", 400);
        set("max_qi", 400);

        set("str", 20);
        set("con", 50);

        set_temp("apply/attack", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/armor", 20);
        set("combat_exp", 50000);
        set_weight(20000);

        setup();
}
void init()
{
        object me,ob;
        if (interactive(me = this_player()))
        {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
        }
        ::init();
}


void die()
{
	object ob, corpse;
	message_vision("$N發出震天動地的一聲長嘯，轟地倒在地上，死了！\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/hugu");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
