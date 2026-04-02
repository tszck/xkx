// zhizhudu.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat","eat");
}

void create()
{
               set_name("蜘蛛毒囊", ({"zhizhu dunang" ,"dunang"}));

                set("unit", "個");
                set("long", "這是一個蜘蛛的毒囊。\n");
                set("value", 100);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(100);


        setup();
}

int do_eat(string arg)
{
    object me = this_player();
    object ob = this_object();
    if (arg != "zhizhu dunang"& arg !="dunang")
    return 0;
    tell_object(me,  "你想死啊，用suicide比較快一點。\n" );
    return 1;
}
