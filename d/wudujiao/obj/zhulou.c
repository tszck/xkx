// zhulou.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_shou","shouchong");
        add_action("do_fang","fangchong");
}

void create()
{
               set_name("竹簍", ({"zhu lou" ,"zl"}));
              set_max_encumbrance(30000);
                set("unit", "個");
                set("long", "這是一個小口大肚的竹簍。\n");
                set("value", 100);
//            set("no_drop", "這樣東西不能離開你。\n");
              set_weight(100);
              set("no_sell",1);
                setup();
}

int do_shou(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
//  ob1= this_object();
    if( !arg
        ||      sscanf(arg, "%s in %s", who, what)!=2)
         return notify_fail("命令格式: shouchong <毒蟲> in <物品>。\n");
    ob1= present(what,me);
    ob = present(who,environment(me));
    if (!ob )
         return notify_fail("你要收什麼？\n");
    if (!ob1 )
         return notify_fail("你要將蟲收到那裏？\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"連理都不理你！\n");
    message_vision("$N打開竹簍，對着"+ob->query("name")+"輕輕吹了一聲口哨。\n",me);
    message_vision("只見"+ob->query("name")+ "身子逐漸縮小，化做一隻幾寸長的小蟲，鑽進了$N的竹簍裏。\n",me);
     ob->move(ob1);
     return 1;
}
int do_fang(string arg)
{
    object me,ob1,ob;
    string who,what;
    me = this_player();
    me = this_player();
//  ob1= this_object();
    if( !arg
        ||      sscanf(arg, "%s from %s", who, what)!=2)
         return notify_fail("命令格式: fangchong <毒蟲> from <物品>。\n");
    ob1 = present(what,me);
    if (!ob1)
         return notify_fail("你要從那裏放毒蟲？\n");
    ob = present(who,ob1);
    if (!ob )
         return notify_fail("你要放什麼？\n");
    if(me->query("id")!=(ob->query("host_id"))||ob->query("age")<100)
         return notify_fail(ob->query("name")+"連理都不理你！\n");
    tell_object(me,  "你悄悄打開竹簍，將裏面的"+ob->query("name")+"放了出來。\n");

    message_vision("忽然，一隻"+ob->query("name")+"不知從什麼地方竄了出來。\n",me);
     ob->move(environment(me));
     return 1;
}
